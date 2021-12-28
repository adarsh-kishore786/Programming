import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    home: Scaffold(
      appBar: AppBar(
        title: Text('I am Poor'),
        backgroundColor: Color.fromRGBO(48, 10, 36, 1),
        centerTitle: true,
        elevation: 10,
        foregroundColor: Colors.blueAccent,
      ),
      body: Column(
        children: [
          Row(
            children: [
              Image(
                image: AssetImage("images/top-left.png"),
              ),
            ],
          ),
          Center(
            child: Image(
              image: AssetImage("images/bottom.png"),
            ),
          )
        ]
      ),
      backgroundColor: Colors.green[600],
    ),
  ));
}