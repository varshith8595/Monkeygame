from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def index():
    # Data to be passed to the template
    user = {'username': 'John Doe', 'age': 30}
    fruits = ['Apple', 'Banana', 'Orange', 'Mango']
    return render_template('index.html', user=user, fruits=fruits)

if __name__ == '__main__':
    app.run(debug=True)