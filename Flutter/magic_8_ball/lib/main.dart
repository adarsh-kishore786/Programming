// @dart=2.9
import 'package:flutter/material.dart';
import 'dart:math';

void main() => runApp(
      MaterialApp(
        home: BallPage(),
      ),
    );

class BallPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.blue[900],
          title: Text("Ask me anything"),
          centerTitle: true,
        ),
        body: Ball(),
        backgroundColor: Colors.blue,
      ),
    );
  }
}

class Ball extends StatefulWidget {
  const Ball({Key key}) : super(key: key);

  @override
  _BallState createState() => _BallState();
}

class _BallState extends State<Ball> {
  int number = 1;
  @override
  Widget build(BuildContext context) {
    return Center(
      child: TextButton(
        child: Image.asset('images/ball${number}.png'),
        onPressed: () {
          setState( () {
            number = Random().nextInt(5) + 1;
          });
        },
      ),
    );
  }
}


