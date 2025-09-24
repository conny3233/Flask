from flask import Flask, render_template, jsonify 
import requests

app = Flask(__name__)
# ESP8266의 IP 주소 (LED 제어하는    서버) 
ESP8266_IP = "http://<ESP8266_IP>/"

@app.route('/') 
def index():
    return render_template('index.html') 
@app.route('/led/on')
def led_on(): 
    try:
        response = requests.get(ESP8266_IP + 'turn_on')
        return jsonify({"status": "LED On"})
    except requests.exceptions.RequestException as e: 
        return jsonify({"error": str(e)}), 500

@app.route('/led/off') 
def led_off():
    try:
        response = requests.get(ESP8266_IP + 'turn_off')
        return jsonify({"status": "LED Off"})
    except requests.exceptions.RequestException as e: return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)