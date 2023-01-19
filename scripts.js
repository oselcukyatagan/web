
function btn_click(){

    // const textHolderNode = document.getElementById("txt_location")

    const paragraph = document.createElement("p")
    // const text2 = textHolderNode.value
    const classElement = document.createAttribute("class")
    classElement.value = "randomText"
    const text = document.createTextNode("frfr")

    paragraph.appendChild(text)
    paragraph.setAttributeNode(classElement)

    document.body.appendChild(paragraph)
}