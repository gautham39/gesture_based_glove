<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
   
</head>
<body>

<h1>Smart Glove Project</h1>

<p>This project implements a smart glove using an ESP32 microcontroller. The glove is equipped with flex sensors on each finger to detect movements and provide specific alerts through an LCD display, buzzer, and GSM module.</p>

<h2>Components Used</h2>
<ul>
    <li>ESP32 Microcontroller</li>
    <li>Flex Sensors (for each finger)</li>
    <li>RGB LCD Display</li>
    <li>Buzzer</li>
    <li>GSM Module (SIM800)</li>
</ul>

<h2>Features</h2>
<ul>
    <li>Detects finger movements using flex sensors.</li>
    <li>Displays messages on an RGB LCD.</li>
    <li>Alerts with a buzzer when specific conditions are met.</li>
    <li>Sends SMS alerts using a GSM module.</li>
</ul>

<h2>How It Works</h2>
<p>The smart glove is designed to detect the bending of fingers using flex sensors. Each sensor is attached to a finger and measures the amount of bending. The ESP32 microcontroller reads the values from these sensors and determines the action to be taken based on predefined conditions:</p>
<ul>
    <li>If the thumb flex sensor value is between a specific range, it indicates that the user needs water. A message is displayed on the LCD, and the buzzer is activated briefly.</li>
    <li>If the index finger flex sensor value is between a specific range, it indicates that the user needs food. A message is displayed on the LCD, and the buzzer is activated briefly.</li>
    <li>If all flex sensor values are within a specific range, it indicates an emergency (HELP). A message is displayed on the LCD, the buzzer is activated in a pattern, and an SMS alert is sent using the GSM module.</li>
</ul>

<h2>Output and Alerts</h2>
<p>The glove outputs data and alerts in several ways:</p>
<ul>
    <li><strong>LCD Display:</strong> Messages are displayed on an RGB LCD, providing visual feedback about the user's needs or an emergency situation.</li>
    <li><strong>Buzzer:</strong> The buzzer is used to produce audible alerts. It activates briefly for needs like water or food and in a pattern for emergencies.</li>
    <li><strong>GSM Module:</strong> In case of an emergency, the GSM module sends an SMS alert to a predefined phone number. This ensures that even if the user is unable to communicate verbally, they can still send out a distress signal.</li>
</ul>

<h2>Communication Protocols</h2>
<p>The smart glove utilizes several communication protocols:</p>
<ul>
    <li><strong>I2C:</strong> The RGB LCD uses the I2C protocol for communication with the ESP32. This protocol is efficient for connecting multiple peripherals with fewer pins.</li>
    <li><strong>UART:</strong> The GSM module communicates with the ESP32 using the UART (Universal Asynchronous Receiver-Transmitter) protocol. UART is commonly used for serial communication, allowing the ESP32 to send and receive messages from the GSM module.</li>
    <li><strong>Analog Input:</strong> The flex sensors provide analog input to the ESP32. The microcontroller reads these values using its ADC (Analog-to-Digital Converter) channels.</li>
</ul>

<h2>Pin Configuration</h2>
<ul>
    <li><code>flex_thumb</code> - Pin 25 (ADC2_CH8)</li>
    <li><code>flex_index</code> - Pin 26 (ADC2_CH9)</li>
    <li><code>flex_middle</code> - Pin 27 (ADC2_CH7)</li>
    <li><code>flex_ring</code> - Pin 14 (ADC2_CH6)</li>
    <li><code>flex_little</code> - Pin 12 (ADC2_CH5)</li>
    <li><code>buzzer</code> - Pin 34</li>
    <li>GSM Module UART2: <code>rx</code> - Pin 16, <code>tx</code> - Pin 17</li>
</ul>

<h2>Future Improvements</h2>
<p>Potential improvements for the smart glove project include:</p>
<ul>
    <li>Adding more sensors to detect additional hand movements or gestures.</li>
    <li>Improving the accuracy and responsiveness of the flex sensors.</li>
    <li>Implementing wireless communication (e.g., Wi-Fi or Bluetooth) for enhanced connectivity.</li>
    <li>Integrating with mobile or web applications for real-time monitoring and alerts.</li>
</ul>

</body>
</html>
