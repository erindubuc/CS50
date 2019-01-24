import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Students who have completed survey
students = []


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    name = request.form.get("name")
    email = request.form.get("email")
    classTime = request.form.get("classTime")
    language = request.form.get("language")

    # If something was not entered into form
    if not name or not email or not classTime or not language:
        return render_template("error.html", message="Please be sure to enter your name and email, AND to choose a favorite langauge.")

    # Upon success -> create sheet and redirect
    file = open("survey.csv", "a")
    writer = csv.writer(file)
    writer.writerow((request.form.get("name"), request.form.get("email"),
                     request.form.get("classTime"), request.form.get("language")))
    file.close()
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():

    # Display submissions in HTML table
    file = open("survey.csv", "r")
    reader = csv.reader(file)
    students = list(reader)
    return render_template("results.html", students=students)