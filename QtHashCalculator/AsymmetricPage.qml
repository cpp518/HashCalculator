import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    spacing: 16

    Text {
        text: "非对称加密配置"
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
                    model: ["RSA", "ECC"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "密钥长度"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["2048", "3072", "4096"]
                }
                Text { text: "bits"; color: "#1B5E20" }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "填充"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["OAEP", "PKCS#1 v1.5"]
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 12
                Text { text: "密钥格式"; color: "#1B5E20"; Layout.preferredWidth: 80 }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["PEM", "DER"]
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
            TextField { Layout.fillWidth: true; placeholderText: "消息内容" }

            Text { text: "示例输出"; font.pixelSize: 16; color: "#1B5E20" }
            TextArea { Layout.fillWidth: true; readOnly: true; text: "RSA: MIIEowIB..." }
        }
    }
}
