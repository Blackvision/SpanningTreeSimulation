#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SPANNINGTREE_MYTOOLS_H
#include "mytools.h"
#endif //SPANNINGTREE_FILEOPTIONS_H
#ifndef SPANNINGTREE_FILEOPTIONS_H
#include "fileoptions.h"
#endif //SPANNINGTREE_FILEOPTIONS_H
#ifndef SPANNINGTREE_DATASTRUCTURE_H_H
#include "datastructure.h"
#endif //SPANNINGTREE_SPANNINGTREE_H
void testfunction();
int main(int argc, char* argv[])
{
    setbuf(stdout, NULL);
    //Prüfe die Parameter, mit denen das Programm aufgerufen wurde.
    if(argc < 2 || argc > 3) {
        writeDebug(
                "Anzahl der Argumente passt nicht.\nEs muss mindestens die Topologiedatei angegeben sein\nAufruf: spt <ToPo File> [Name des Graphen]\n");
    }
    //Kopiere den ersten Parameter in eine persitente Variable.
    char *filename;
    filename = xmalloc(sizeof(argv[1] + 1));
    strcpy(filename, argv[1]);
    //Prüfe die exitenz und lesbarkeit der Definitionsdatei
    if(fileReadable(filename) != 0)
    {
        writeDebug("Datei nicht lesbar.");
        return 1;
    }
    testfunction();
    return 0;
}
void testfunction()
{
    p_node nodelist;
    nodelist = 0;
    p_link linklist;
    linklist = 0;
    p_node testnode = createNode("Beta1", 1);
    p_node testnode2 = createNode("Beta2", 2);
    p_link testlink = createLink(12, &testnode2, &testnode);
    p_link testlink2 = createLink(9, &testnode2, &testnode);
    if(testnode == 0)
    {
        writeDebug("Fehler beim erstellen des Testnodes.");
    }else{
        addNodeToList(testnode, &nodelist);
        writeDebug("Füge zweiten Node hinzu:");
        addNodeToList(testnode2,&nodelist);
        writeDebug("Das Element 1 befindet sich in der Liste?");
        writeDebug(itoa(isInNodeList(testnode, &nodelist)));
        writeDebug("Das Element der Name Beta1 befindet sich in der Liste?");
        writeDebug(ptoa(nodeExitsByName("Beta1", &nodelist)));
        writeDebug("Das Element der ID 1 befindet sich in der Liste?");
        writeDebug(ptoa(nodeExitsByID(1, &nodelist)));
        writeDebug("Entferne Node aus Liste");
        removeNodeFromList(testnode,&nodelist);
        writeDebug("Lösche Node");
        deleteNode(&testnode);
        printNode(testnode);
        writeDebug("Das Element 1 befindet sich in der Liste?");
        writeDebug(itoa(isInNodeList(testnode, &nodelist)));
        writeDebug("Die Nodeliste hat noch folgenden Pointer");
        writeDebug(ptoa(nodelist));
    }
    if(testlink == 0)
    {
        writeDebug("Fehler beim erstellen des Testlinks.");
    }else{
        addLinkToLinklist(testlink, &linklist);
        writeDebug("Das Element befindet sich noch in der Liste?");
        writeDebug(itoa(isInLinkList(testlink, &linklist)));
        writeDebug("Das Element von Node 1 zu 2 befindet sich noch in der Liste?");
        writeDebug(itoa(linkExists(testnode, testnode2, &linklist)));
        writeDebug("Füge zweiten Link hinzu:");
        addLinkToLinklist(testlink2,&linklist);
        writeDebug("Entferne link aus Liste");
        removeLinkFromList(testlink,&linklist);
        writeDebug("Lösche Link");
        deleteLink(&testlink);
        printLink(testlink);
        writeDebug("Das Element befindet sich noch in der Liste?");
        writeDebug(itoa(isInLinkList(testlink, &linklist)));
        writeDebug("Die Linkliste hat noch folgenden Pointer");
        writeDebug(ptoa(linklist));
    }
}