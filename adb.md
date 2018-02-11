### Build & Install Android Apps From Commandline
```sh
>> gradle build && adb install -r app\build\outputs\apk\app-all-debug.apk && adb shell am start -n codecafe.com.ui/.MainActivity
>> adb shell am kill com.google.android.contacts [Terminate]
>> adb shell am force-stop com.google.android.contacts [Or More Drastic]
```
### Connect Adb Device Over Wifi
```
>> [Connect Android Via USB Through "Files"]
>> adb devices
>> adb start-server
>> adb tcpip 5556
>> adb connect 192.168.247.251:5556 [Connected Wifi IP of Phone][About Phone >> Status >> IP address]
>> [Disconnect Device From USB]
>> adb devices [List of devices attached : 192.168.247.251:5556  device]
```
