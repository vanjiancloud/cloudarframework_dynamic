CloudAR is a ar tool library in Swift.

## Features

- AR
- BIM

### Configuration framework

First thing to use CloudAR sdk is to configure the following framework

- CloudAR.framework
- StreamSdk.framework
- Starscream.framework
- Alamofire.framework

### Import  CloudAR

```
import CloudAR
```





#### AR

After importing framework, you can use BIMModelController class  as subController to show ar view and to position; in this version, only scan position func is enabled

##### Position

Calling following func  *enterPosition*(). you can scan specific qrcode, downloading from vanjian's ourbim website, to locate current position in engine

```swift
BIMModelController.enterPosition(type: VJARPositionType)
```

This function is used to start position,and you should hidden BIMModelController's view before that

```
BIMModelController.view.isHidden = true
```

After comfirm position, BIMModelController will to show view automatically. then you could interact with model in engine.

