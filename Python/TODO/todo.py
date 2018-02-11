""" To-do list where
    where you can add tasks modify them
    and mark them if they have been completed
"""

from collections import OrderedDict
import datetime
import os

from peewee import *

db = SqliteDatabase('to_do_list.db')


class ToDo(Model):
    task = CharField(max_length=255)
    timestamp = DateTimeField(default=datetime.datetime.now)
    done = BooleanField(default=False)
    proteted = BooleanField(default=False)

    class Meta:
        database = db


def clear():
    os.system('cls' if os.name == 'nt' else 'clear')


def initialize():
    db.connect()
    db.create_tables([ToDo], safe=True)


def view_entries(index, entries, single_entry):
    clear()


    index = index % len(entries)
