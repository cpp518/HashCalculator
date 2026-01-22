import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    spacing: 16

    Text {
        text: "哈希配置"
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

                Text { text: "算法"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["MD5", "SHA-1", "SHA-256", "SHA-512"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12

                Text { text: "输出编码"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["Hex", "Base64"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12

                Text { text: "盐值(可选)"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                TextField { Layout.fillWidth: true; placeholderText: "可为空" }
            }
        }
    }

    Rectangle {
        Layout.fillWidth: true
        radius: 10
        color: "#E8F5E9"
        height: 140

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 16
            spacing: 8

            Text { text: "示例输入"; font.pixelSize: 16; color: "#1B5E20" }
            TextField { Layout.fillWidth: true; placeholderText: "hello world" }

            Text { text: "示例输出"; font.pixelSize: 16; color: "#1B5E20" }
            TextArea { Layout.fillWidth: true; readOnly: true; text: "2ef7bde6..." }
        }
    }
}
