import java.util.ArrayList;
import javax.swing.JOptionPane;

public class ScheduleClass 
{
	int num = 0;
	String arr[][]= new String[7][4];
	public ScheduleClass()
	{
		
	}
	ArrayList<String> b = new ArrayList<String>();
	public void addEvent()
	{
		String desc = JOptionPane.showInputDialog("Enter in Event description");
		String date = JOptionPane.showInputDialog("Enter in date");
		String priority = JOptionPane.showInputDialog("Enter priority from 1-3 *'s");
		
		arr[num][1] = desc;
		arr[num][2] = date;
		arr[num][3] = priority;
		num++;
		
	}
	public void deleteEvent()
	{
		String delete = JOptionPane.showInputDialog("Which event would you like to delete?");
		int num1 = 0;
		for(int i = 0; i < arr.length; i++)
		{
			if(arr[num1][1].equals(delete))
			{
				arr[num1][1] = " ";
			}
			else
				num1++;
		}
		
		//arr[num][1] = " ";
	}
	public void printOut()
	{
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[i].length; j++)
			{
				JOptionPane.showMessageDialog(null, arr[i][j]);
			}
		}
	}
}		