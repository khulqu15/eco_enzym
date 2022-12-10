import 'package:flutter/material.dart';
import 'package:toggle_switch/toggle_switch.dart';
import 'dimensions.dart';

class MyDesktopBody extends StatelessWidget {
  const MyDesktopBody({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    Size screenSize = MediaQuery.of(context).size;

    return SingleChildScrollView(
      // appBar: AppBar(
      //   backgroundColor: Colors.white,
      //   toolbarHeight: 80,
      //   title: Text(
      //     widget.title,
      //   ),
      //   titleTextStyle: const TextTheme(
      //           headline6: TextStyle(
      //               color: Colors.black87,
      //               fontSize: 24,
      //               fontWeight: FontWeight.bold))
      //       .headline6,
      // ),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.start,
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Container(
              margin: const EdgeInsets.only(top: 36.0, left: 36),
              width: screenSize.width < mobileWidth ? double.infinity : 320,
              height: 64,
              padding: const EdgeInsets.symmetric(vertical: 18.0, horizontal: 20),
              decoration: BoxDecoration(
                color: Colors.white,
                boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.15), spreadRadius: -18.0, blurRadius: 51, offset: const Offset(0, 4))],
                borderRadius: screenSize.width < mobileWidth
                    ? const BorderRadius.only(topLeft: Radius.circular(12.0), bottomLeft: Radius.circular(12.0))
                    : const BorderRadius.all(Radius.circular(12.0)),
              ),
              child: const Text(
                "Eco Enzym",
                style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Colors.green),
              )),
          Center(
            child: Container(
              margin: const EdgeInsets.only(top: 80.0),
              child: Row(mainAxisAlignment: MainAxisAlignment.center, crossAxisAlignment: CrossAxisAlignment.center, children: [
                Container(
                    margin: const EdgeInsets.symmetric(horizontal: 8.0),
                    width: 360,
                    height: 80,
                    decoration: BoxDecoration(
                        color: Colors.white,
                        boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.15), spreadRadius: -18, blurRadius: 51, offset: const Offset(0, 4))],
                        borderRadius: const BorderRadius.all(Radius.circular(16.0))),
                    child: Container(
                      margin: const EdgeInsets.symmetric(horizontal: 16.0),
                      child: Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, crossAxisAlignment: CrossAxisAlignment.center, children: [
                        Container(
                          width: 50,
                          height: 50,
                          decoration: BoxDecoration(borderRadius: const BorderRadius.all(Radius.circular(8.0)), color: Colors.green.withOpacity(0.2)),
                          child: const Icon(
                            Icons.wifi,
                            color: Colors.green,
                          ),
                        ),
                        const Text(
                          "Connected",
                          style: TextStyle(fontSize: 18, fontWeight: FontWeight.w500),
                        )
                      ]),
                    )),
                Container(
                    margin: const EdgeInsets.symmetric(horizontal: 8.0),
                    width: 360,
                    height: 80,
                    decoration: BoxDecoration(
                        color: Colors.white,
                        boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.15), spreadRadius: -18, blurRadius: 51, offset: const Offset(0, 4))],
                        borderRadius: const BorderRadius.all(Radius.circular(16.0))),
                    child: Container(
                      margin: const EdgeInsets.symmetric(horizontal: 16.0),
                      child: Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, crossAxisAlignment: CrossAxisAlignment.center, children: [
                        const Text(
                          "Katup",
                          style: TextStyle(fontSize: 18, fontWeight: FontWeight.w500),
                        ),
                        ToggleSwitch(
                          cornerRadius: 8.0,
                          activeBgColors: const [
                            [Colors.green],
                            [Colors.red]
                          ],
                          activeFgColor: Colors.white,
                          inactiveBgColor: Colors.grey[200],
                          totalSwitches: 2,
                          labels: ['Open', 'Close'],
                          icons: [null, null],
                          onToggle: (index) {
                            print(index);
                          },
                        ),
                      ]),
                    )),
              ]),
            ),
          ),
          // Monitoring Content
          Center(
            child: Container(
              margin: const EdgeInsets.only(top: 30.0),
              child: Row(mainAxisAlignment: MainAxisAlignment.center, crossAxisAlignment: CrossAxisAlignment.center, children: [
                Container(
                    margin: const EdgeInsets.symmetric(horizontal: 8.0),
                    width: 360,
                    height: 200,
                    decoration: BoxDecoration(
                        color: Colors.white,
                        boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.15), spreadRadius: -18, blurRadius: 51, offset: const Offset(0, 4))],
                        borderRadius: const BorderRadius.all(Radius.circular(16.0))),
                    child: Container(
                        margin: const EdgeInsets.all(16.0),
                        child: Column(
                          children: [
                            Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, crossAxisAlignment: CrossAxisAlignment.center, children: [
                              Container(
                                height: 50,
                                padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 14),
                                margin: const EdgeInsets.only(bottom: 36.0),
                                decoration: BoxDecoration(borderRadius: const BorderRadius.all(Radius.circular(8.0)), color: Colors.green.withOpacity(0.2)),
                                child: const Text(
                                  'Sensor Ph',
                                  style: TextStyle(color: Colors.green, fontSize: 18, fontWeight: FontWeight.w500),
                                ),
                              ),
                            ]),
                            Row(
                              mainAxisAlignment: MainAxisAlignment.spaceBetween,
                              crossAxisAlignment: CrossAxisAlignment.center,
                              children: [
                                Row(
                                  mainAxisAlignment: MainAxisAlignment.start,
                                  crossAxisAlignment: CrossAxisAlignment.end,
                                  children: [
                                    Container(
                                      margin: EdgeInsets.only(right: 8.0),
                                      child: Text(
                                        '30%',
                                        style: TextStyle(fontSize: 64.0, fontWeight: FontWeight.bold),
                                      ),
                                    ),
                                    Container(
                                      margin: const EdgeInsets.only(bottom: 12),
                                      child: Text(
                                        'Asam',
                                        style: TextStyle(fontSize: 20.0),
                                      ),
                                    ),
                                  ],
                                ),
                                Container(
                                  margin: const EdgeInsets.only(right: 12.0),
                                  width: 60,
                                  height: 60,
                                  decoration: const BoxDecoration(color: Colors.green, borderRadius: BorderRadius.all(Radius.circular(8.0))),
                                )
                              ],
                            )
                          ],
                        ))),
                Container(
                    margin: const EdgeInsets.symmetric(horizontal: 8.0),
                    width: 360,
                    height: 200,
                    decoration: BoxDecoration(
                        color: Colors.white,
                        boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.15), spreadRadius: -18, blurRadius: 51, offset: const Offset(0, 4))],
                        borderRadius: const BorderRadius.all(Radius.circular(16.0))),
                    child: Container(
                        margin: const EdgeInsets.all(16.0),
                        child: Column(
                          children: [
                            Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, crossAxisAlignment: CrossAxisAlignment.center, children: [
                              Container(
                                height: 50,
                                padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 14),
                                margin: const EdgeInsets.only(bottom: 36.0),
                                decoration: BoxDecoration(borderRadius: const BorderRadius.all(Radius.circular(8.0)), color: Colors.green.withOpacity(0.2)),
                                child: const Text(
                                  'Alcohol Sensor',
                                  style: TextStyle(color: Colors.green, fontSize: 18, fontWeight: FontWeight.w500),
                                ),
                              ),
                            ]),
                            Row(
                              mainAxisAlignment: MainAxisAlignment.end,
                              crossAxisAlignment: CrossAxisAlignment.center,
                              children: [
                                Row(
                                  mainAxisAlignment: MainAxisAlignment.start,
                                  crossAxisAlignment: CrossAxisAlignment.end,
                                  children: [
                                    Container(
                                      margin: EdgeInsets.only(right: 8.0),
                                      child: Text(
                                        '30%',
                                        style: TextStyle(fontSize: 64.0, fontWeight: FontWeight.bold),
                                      ),
                                    ),
                                    Container(
                                      margin: const EdgeInsets.only(bottom: 12),
                                      child: Text(
                                        'Asam',
                                        style: TextStyle(fontSize: 20.0),
                                      ),
                                    ),
                                  ],
                                ),
                              ],
                            )
                          ],
                        ))),
              ]),
            ),
          )
        ],
      ),
      // floatingActionButton: FloatingActionButton(
      //   onPressed: _incrementCounter,
      //   tooltip: 'Increment',
      //   child: const Icon(Icons.add),
      // ),
    );
  }
}
