import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.teal,
        body: SafeArea(
          child: Row(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Container(
                color: Colors.red,
                width: 100.0,

              ),
              Column(
                mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Container(
                      decoration: BoxDecoration(
                        color: Color.fromRGBO(48, 10, 36, 1),
                        border: Border.all(
                          color: Colors.white,
                          width: 3.0,
                        )
                      ),
                      child: Align(
                        alignment: Alignment.center,
                        child: Text(
                          'App Layout',
                          maxLines: 5,
                          textAlign: TextAlign.center,
                          style: const TextStyle(
                            fontWeight: FontWeight.bold,
                            fontSize: 30.0,
                            fontStyle: FontStyle.italic,
                            color: Colors.lightBlue,
                          ),
                        ),
                      ),
                      height: 100.0,
                      width: 100.0,
                    ),
                    Container(
                      color: Colors.yellow,
                      width: 100.0,
                      height: 100.0
                    ),
                    Container(
                        color: Colors.green,
                        width: 100.0,
                        height: 100.0
                    ),
                    const FlutterLogo(
                      size: 100,
                    ),
                ],
              ),
              Container(
                color: Colors.blue,
                width: 100.0,
              ),
            ],
          ),
        ),
      ),
    );
  }
}
