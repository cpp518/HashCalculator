import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    spacing: 16

    Text {
        text: "对称加密配置"
        font.pixelSize: 22
        font.bold: true
        color: "#1B5E20"
    }

    Rectangle {
        Layout.fillWidth: true
        radius: 10
        color: "#C8E6C9"
        height: 220

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
                    model: ["AES", "ChaCha20"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "密钥长度"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["128", "192", "256"]
                }
                Text { text: "bits"; color: "#1B5E20" }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "模式"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["GCM", "CBC", "CTR"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "IV长度"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["96", "128"]
                }
                Text { text: "bits"; color: "#1B5E20" }
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
            TextField { Layout.fillWidth: true; placeholderText: "敏感文本内容" }

            Text { text: "示例输出"; font.pixelSize: 16; color: "#1B5E20" }
            TextArea { Layout.fillWidth: true; readOnly: true; text: "Base64: o2zY2x..." }
        }
    }
}
