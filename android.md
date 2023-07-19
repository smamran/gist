## Stores Temporary apks After Installation 
```sh
/data/local/tmp
```
## Forcefully Uninstalled System Apps
```sh
adb shell pm uninstall --user 0 <package_name>
pm list packages calculator
pm uninstall --user 0 com.android.calculator2
```
## List Disabled Apps
` pm list packages -d `

## Disable App
` pm disable com.facebook.katana `

## Enable App
` pm enable com.facebook.katana `

## List Users
` pm list users `

## User Specific Disable/Enable App
```sh
pm disable --user 0 com.facebook.katana
pm enable --user 0 com.facebook.katana
```
