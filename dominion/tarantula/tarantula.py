#!/usr/bin/python


def main():
    # all_data = {line_1: {'pass': #, 'fail': #},
    #             line_2: {'pass': #, 'fail': #},
    #              ...}
    all_data = {}
    # metadata =  {'title': test_title,
    #              'filepath': gcov_filepath,
    #              'status': pass/fail}
    all_metadata = process_test('tests.txt')
    for metadata in all_metadata:
        process_gcov(metadata, all_data)

    suspicious_rating(all_metadata, all_data)

    for line in all_data:
        if all_data[line]['sus'] > 0.6:
            print('line #' + str(line) + ' has a suspicious rating of ' +
                   str(all_data[line]['sus']) + ':')
            print('\t' + all_data[line]['code'] + '\n')

"""
Calculates suspiciousness of each line
"""
def suspicious_rating(all_meta, data):
    failures = sum([1 for x in all_meta if x['status'] == 'fail'])
    passes = sum([1 for x in all_meta if x['status'] == 'pass'])
    for line in data:
        try:
            fail_ratio = float(data[line]['fail']) / (failures)
        except ZeroDivisionError:
            fail_ratio = 0

        try:
            pass_ratio = float(data[line]['pass']) / (passes)
        except ZeroDivisionError:
            pass_ratio = 0

        sus = fail_ratio / (pass_ratio + fail_ratio)
        data[line]['sus'] = sus

"""
Processes a gcov and returns a dictionary
"""
def process_gcov(meta, data):
    with open(meta['filepath']) as f:
        for line in f:
            line_list = line.strip().split(':')
            if line_list[0] == '-':
                continue
            # line_data = {'lineno': #,
            #              'code': code_snippet,
            #              'raw': raw_line,
            #              'times_run': #}
            line_data = {}
            line_data['lineno'] = int(line_list[1].strip())
            line_data['code'] = line_list[2].strip()
            line_data['raw'] = line.strip('\n')

            try:
                line_data['times_run'] = int(line_list[0].strip())
            except:
                line_data['times_run'] = 0

            if line_data['times_run'] == 0:
                try:
                    data[line_data['lineno']][meta['status']] += 1
                except KeyError:
                    data[line_data['lineno']]= {'pass': 0, 'fail': 0, 'code': line_data['code']}
                    data[line_data['lineno']][meta['status']] = 1

"""
Given an analyze file outputs a dict of titles, files, and pass/fail status
"""
def process_test(input_file):
    with open(input_file) as f:
        process_file = []
        for line in f:
            info = {}

            l = line.split()
            info['title']    = l[0]
            info['filepath'] = l[1]
            info['status']   = l[2]

            process_file.append(info)

    return process_file

# execute main
if __name__ == '__main__':
    main()
