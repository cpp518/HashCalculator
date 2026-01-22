import QtQuick
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1200
    height: 800
    title: "绿色主题加解密工具"
    property string selectedType: "哈希"
    property var typeMethods: ({
        "哈希": ["MD5", "SHA-1", "SHA-256", "SHA-512"],
        "对称加密": ["AES-256-GCM", "AES-128-CBC", "ChaCha20-Poly1305"],
        "非对称加密": ["RSA-2048/3072", "ECC(ECDH/ECDSA)", "SM2(可选)"],
        "其他编码": ["Base64", "Hex", "URL Encode/Decode"]
    })
    property var typeTips: ({
        "哈希": "哈希为单向摘要，不可逆，用于校验与完整性验证。",
        "对称加密": "加解密使用同一密钥，注意密钥安全与随机 IV。",
        "非对称加密": "使用公钥/私钥配对，适合密钥交换与签名。",
        "其他编码": "编码不是加密，不提供安全性，仅用于格式转换。"
    })

    // 设置窗口背景颜色为绿色
    color: "#4CAF50"

    // 主要内容区域
    Rectangle {
        id: contentArea
        anchors.fill: parent
        color: "transparent"

        // 左侧菜单栏
        Rectangle {
            id: menuPanel
            width: 250
            height: parent.height
            color: "#2E7D32" // 深绿色作为菜单背景
            radius: 10

            // 菜单阴影效果
            layer.enabled: true
            layer.effect: DropShadow {
                transparentBorder: true
                color: "#40000000"
                radius: 20
                samples: 41
                horizontalOffset: 5
                verticalOffset: 0
            }

            ColumnLayout {
                id: menuLayout
                anchors.fill: parent
                anchors.margins: 20
                spacing: 10

                // 菜单标题
                Text {
                    id: menuTitle
                    text: "密码类型"
                    font.pixelSize: 24
                    font.bold: true
                    color: "white"
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 20
                    Layout.bottomMargin: 30
                }

                // 菜单项
                MenuButton {
                    id: hashButton
                    text: "🧾 哈希"
                    iconColor: "#81C784"
                    Layout.fillWidth: true
                    onClicked: {
                        selectedType = "哈希"
                        contentLoader.source = "HashPage.qml"
                        resetButtons()
                        isActive = true
                    }
                }

                MenuButton {
                    id: symmetricButton
                    text: "🔐 对称加密"
                    iconColor: "#81C784"
                    Layout.fillWidth: true
                    onClicked: {
                        selectedType = "对称加密"
                        contentLoader.source = "SymmetricPage.qml"
                        resetButtons()
                        isActive = true
                    }
                }

                MenuButton {
                    id: asymmetricButton
                    text: "🔑 非对称加密"
                    iconColor: "#81C784"
                    Layout.fillWidth: true
                    onClicked: {
                        selectedType = "非对称加密"
                        contentLoader.source = "AsymmetricPage.qml"
                        resetButtons()
                        isActive = true
                    }
                }

                MenuButton {
                    id: encodingButton
                    text: "🧩 其他编码"
                    iconColor: "#81C784"
                    Layout.fillWidth: true
                    onClicked: {
                        selectedType = "其他编码"
                        contentLoader.source = "EncodingPage.qml"
                        resetButtons()
                        isActive = true
                    }
                }

                // 占位空间
                Item {
                    Layout.fillHeight: true
                }

                // 退出按钮
                MenuButton {
                    id: exitButton
                    text: "🚪 退出"
                    iconColor: "#EF5350"
                    Layout.fillWidth: true
                    Layout.bottomMargin: 20
                    onClicked: Qt.quit()
                }
            }
        }

        // 右侧内容区域
        Rectangle {
            id: rightPanel
            anchors {
                left: menuPanel.right
                right: parent.right
                top: parent.top
                bottom: parent.bottom
                margins: 30
            }
            color: "#E8F5E9" // 浅绿色背景
            radius: 15

            // 内容区域阴影效果
            layer.enabled: true
            layer.effect: DropShadow {
                transparentBorder: true
                color: "#20000000"
                radius: 15
                samples: 31
                horizontalOffset: 3
                verticalOffset: 3
            }

            // 内容区域标题
            Text {
                id: contentTitle
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                    margins: 30
                }
                text: "当前类型：" + selectedType
                font.pixelSize: 32
                font.bold: true
                color: "#1B5E20"
            }

            // 内容区域说明
            Text {
                id: contentDescription
                anchors {
                    top: contentTitle.bottom
                    left: parent.left
                    right: parent.right
                    margins: 30
                    topMargin: 15
                }
                text: "从左侧选择类型，右侧显示对应的参数配置、密钥长度和示例输入输出。"
                font.pixelSize: 18
                color: "#2E7D32"
                wrapMode: Text.WordWrap
            }

            // 内容加载器
            Loader {
                id: contentLoader
                anchors {
                    top: contentDescription.bottom
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                    margins: 30
                    topMargin: 30
                }
                source: "HashPage.qml"
            }
        }
    }

    // 自定义菜单按钮组件
    Component {
        id: menuButtonComponent

        Rectangle {
            id: buttonRoot
            property alias text: buttonText.text
            property color iconColor: "#81C784"
            property bool isActive: false

            signal clicked

            height: 60
            radius: 8
            color: isActive ? "#1B5E20" : "transparent"

            Row {
                anchors.fill: parent
                anchors.leftMargin: 20
                spacing: 15

                Rectangle {
                    id: iconContainer
                    width: 30
                    height: 30
                    radius: 15
                    color: iconColor
                    anchors.verticalCenter: parent.verticalCenter

                    Text {
                        id: iconText
                        anchors.centerIn: parent
                        font.pixelSize: 16
                    }
                }

                Text {
                    id: buttonText
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 18
                    color: "white"
                }
            }

            // 鼠标悬停效果
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor

                onEntered: {
                    if (!buttonRoot.isActive) {
                        buttonRoot.color = "#388E3C"
                    }
                }

                onExited: {
                    if (!buttonRoot.isActive) {
                        buttonRoot.color = "transparent"
                    }
                }

                onClicked: {
                    buttonRoot.clicked()
                }
            }
        }
    }

    // 菜单按钮组件（使用上面定义的组件）
    Component.onCompleted: {
        // 设置默认激活的按钮
        hashButton.isActive = true
        contentLoader.source = "HashPage.qml"
    }

    // 重置所有按钮的激活状态
    function resetButtons() {
        hashButton.isActive = false
        symmetricButton.isActive = false
        asymmetricButton.isActive = false
        encodingButton.isActive = false
    }
}
