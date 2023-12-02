import csv
csv_file_path = 'people_data.csv'

with open(csv_file_path, 'r') as file:
    lines = file.readlines()


    header = lines[0].strip().split('\t')
    
    data_lines = [line.strip().split('\t') for line in lines[1:]]
result=[]
for data in header.split(","):
    result.append(data)
name = result[0]
gender = result[1]
age = result[2]
country = result[3]
height = result[4]

total_age = 0
num_people = 0

total_male_height = 0
num_male = 0

country_counts = {}

for line in data_lines:
    total_age += int(line[age])
    num_people += 1

    if line[gender] == 'Male':
        total_male_height += int(line[height])
        num_male += 1

    country = line[country]
    country_counts[country] = country_counts.get(country, 0) + 1

average_age = total_age / num_people
average_male_height = total_male_height / num_male
most_common_country = max(country_counts, key=country_counts.get)

print(f"Age의 평균: {average_age}")
print(f"남자의 Height의 평균: {average_male_height}")
print(f"가장 많이 나오는 나라: {most_common_country}")