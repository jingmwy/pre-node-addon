# description
该次版本基于node7.9.0，v8版本5.5.372.43，底层代码是采用暴力时代的V8代码编写
# code
实现流程如下：
* 1.package.json中添加如下配置：
    "dependencies": {
        "node-pre-gyp": "^0.14.0"
    },
    "devDependencies": {
        "aws-sdk": "^2.600.0"
    },
    "scripts": {
        "install": "node-pre-gyp install --fallback-to-build"
    },
    "binary": {
        "module_name": "your_module",
        "module_path": "./lib/binding/",
        "host": "https://your_module.s3-us-west-1.amazonaws.com"
    }
* 2.binding.gyp中追加如下：
    {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "<(module_name)" ],
      "copies": [
        {
          "files": [ "<(PRODUCT_DIR)/<(module_name).node" ],
          "destination": "<(module_path)"
        }
      ]
    }
* 3.在index.json中添加如下配置：
```javascript
var binary = require('node-pre-gyp');
var path = require('path');
var binding_path = binary.find(path.resolve(path.join(__dirname,'./package.json')));
var binding = require(binding_path);
```

* 4.在本地编译你的c文件
    npm install --build-from-source  （32位的需要添加指令--target_arch=ia32）
    或者node-pre-gyp rebuild --build-from-source
* 5.测试 
    npm test
* 6.打包发布
    node-pre-gyp package