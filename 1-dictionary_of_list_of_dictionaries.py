#!/usr/bin/python3
'''
    This module contains a Python script that gathers data from an API.

    Given an employee ID, the script returns information about their
    To-Do list progress.
'''

import json
import requests
from sys import argv

if __name__ == '__main__':
    url_api = "https://jsonplaceholder.typicode.com"
    export_file = "todo_all_employees.json"
    return_dict = {}

    for employee_id in range(1, 11):
        url_employee = "{}/users/{}".format(url_api, employee_id)
        employee = requests.get(url_employee).json()
        employee_name = employee['name']

        url_employee_todos = "{}/todos?userId={}".format(url_api, employee_id)
        employee_todos = requests.get(url_employee_todos).json()

        employee_list = []
        for task in employee_todos:
            task_dict = {}
            task_dict["username"] = employee_name
            task_dict["task"] = task['title']
            task_dict["completed"] = task['completed']
            employee_list.append(task_dict)
        return_dict[str(employee_id)] = employee_list

    with open(export_file, 'w') as file_pointer:
        json.dump(return_dict, file_pointer)

