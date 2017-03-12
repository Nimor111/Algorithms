import re


def time_conversion(time):
    times = {
        '01': '13',
        '02': '14',
        '03': '15',
        '04': '16',
        '05': '17',
        '06': '18',
        '07': '19',
        '08': '20',
        '09': '21',
        '10': '22',
        '11': '23',
        '12': '12'
        }
    if time == '12:00:00AM':
        return '00:00:00'
    elif time == '12:00:00PM':
        return '12:00:00'
    elif 'AM' in time:
        time = re.sub('12', '00', time)
        return re.sub('AM', '', time)
    elif 'PM' in time:
        for k, v in times.items():
            if k == time[0] + time[1]:
                time = re.sub(k, v, time, 1)
                time = re.sub('PM', '', time)
                return time


def main():
    while True:
        time = input().strip()
        print(time_conversion(time))


if __name__ == '__main__':
    main()
