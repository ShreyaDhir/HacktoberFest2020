public class MakeString{
    
    public static void main(String[] args){
        makePoetry();
    }

    public static void makePoetry(){
        //System.out.println(txt);
        String text = "Hello guys \n try this awesome program\n";
        int i;
        for(i = 0; i < text.length(); i++){
            System.out.printf("%c", text.charAt(i));
            try{
                Thread.sleep(75);//0.5s pause between characters
            }catch(InterruptedException ex){
                Thread.currentThread().interrupt();
            }
        }
}
}