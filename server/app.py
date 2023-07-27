from flask import Flask, request
from flask_cors import CORS


app = Flask(__name__)
cors = CORS(app)


@app.route('/')
def hello_world():  # put application's code here
    if request.method == "GET":
        response = {0, 1, 2, 3, 4, 5, 6, 7}
        


if __name__ == '__main__':
    app.run()
