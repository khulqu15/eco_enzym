import 'package:flutter/material.dart';
import 'package:toggle_switch/toggle_switch.dart';
import 'package:eco_enzym/layout/desktop_body.dart';
import 'package:eco_enzym/layout/mobile_body.dart';
import 'package:eco_enzym/layout/responsive_layout.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Eco Enzym'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    Size screenSize = MediaQuery.of(context).size;
    return Scaffold(
      resizeToAvoidBottomInset: false,
      body: ResponsiveLayout(
        desktopBody: MyDesktopBody(),
        mobileBody: MyMobileBody(),
      ),
    );
  }
}
