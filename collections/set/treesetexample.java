import java.util.*;
class treesetexample{
public static void main(String args[]){
String words[]="repeat word are different word is are repeat are".split("[. ]+");;
TreeSet s=new TreeSet();
for(String w:words)
s.add(w);
System.out.println(s.size());
Iterator i=s.iterator();
while(i.hasNext()){
System.out.println(i.next());
}
}
}
