import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    spacing: 16

    Text {
        text: "其他编码配置"
        font.pixelSize: 22
        font.bold: true
        color: "#1B5E20"
    }

    Rectangle {
        Layout.fillWidth: true
        radius: 10
        color: "#C8E6C9"
        height: 170

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 16
            spacing: 10

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "编码类型"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["Base64", "Hex", "URL Encode/Decode"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "方向"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["编码", "解码"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "字符集"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["UTF-8", "GBK"]
                }
            }
        }
    }

    Rectangle {
        Layout.fillWidth: true
        radius: 10
        color: "#E8F5E9"
        height: 170

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 16
            spacing: 8

            Text { text: "示例输入"; font.pixelSize: 16; color: "#1B5E20" }
            TextField { Layout.fillWidth: true; placeholderText: "hello world" }

            Text { text: "示例输出"; font.pixelSize: 16; color: "#1B5E20" }
            TextArea { Layout.fillWidth: true; readOnly: true; text: "aGVsbG8gd29ybGQ=" }
        }
    }
}
