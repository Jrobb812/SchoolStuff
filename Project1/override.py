from flask import Flask, render_template, session, redirect, url_for
from flask_bootstrap import Bootstrap
from flask_moment import Moment
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from wtforms.validators import DataRequired
from flask import request

app = Flask(__name__)
app.config['SECRET_KEY'] = 'temporarySolutionKey'

bootstrap = Bootstrap(app)
moment = Moment(app)

class OverrideForm(FlaskForm):

    name = StringField('Student Name: ', validators=[DataRequired()])
    studentID = StringField('Student ID: ', validators=[DataRequired()])
    course = StringField('Course: ', validators=[DataRequired()])
    section = StringField('Section Number: ', validators=[DataRequired()])
    crn = StringField('CRN: ', validators=[DataRequired()])
    submit = SubmitField('Submit')

class EmptyForm(FlaskForm):
    name = 'n/a'

@app.route('/', methods = ['GET', 'POST'])
def index():
    form = OverrideForm()
    if form.validate_on_submit():
        session['course'] = form.course.data
        return redirect(url_for('confirmation'))
        #return render_template('confirmation.html', form=form, course=session.get('course'))
    return render_template('index.html', form=form)

@app.route('/confirmation')
def confirmation():
    return render_template('confirmation.html')

@app.errorhandler(404)
def page_not_found(e):
     return render_template('404.html'), 404

@app.errorhandler(500)
def internal_server_error(e):
    return render_template('500.html'), 500

# if __name__ == "__main__":
#     app.debug = True
#     app.run(host = '0.0.0.0', port=5000)