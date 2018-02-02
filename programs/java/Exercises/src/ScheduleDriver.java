import javax.swing.JOptionPane;

public class ScheduleDriver 
{
	public static void main(String[] args) 
	{
		ScheduleClass a = new ScheduleClass();
		boolean flag = true;
		do
		{
			String choice = JOptionPane.showInputDialog("Choose 1] add event \n 2] Delete an event \n 3] prioritize event \n 4] print out schedule \n 5] end program");
			int c = Integer.parseInt(choice);
			if(c == 1)
			a.addEvent();
			if(c==2)
			a.deleteEvent();
			if(c==3)
			a.printOut();
			if(c==4)
			flag = false;
		} while(flag);
	}
}
