import QtQuick 2.12
import QtQuick.Controls 2.12



GridView {
   id: map_view
   cellHeight: height / 10
   cellWidth: width / 10

   signal cellClicked(int index)
   model: mapmodel
   delegate: Item {
       id: cellDelegate
       width: map_view.cellWidth
       height: map_view.cellHeight

       Cell {
           anchors.fill: cellDelegate
           anchors.margins: 5
           id: cells
           color: isRevealed ? "green" : "grey"

           MouseArea 	{
               anchors.fill: parent
               onClicked: {
                   if (isClickable)
                    mapmodel.onCellClicked(index)

                       }

                        }

        }
    }

}






