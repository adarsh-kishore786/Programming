public class Date {
    private int date;
    private int month;
    private int year;

    public Date(int date, int month, int year)
    {
        this.date = date;
        this.month = month;
        this.year = year;
    }

    public Date()
    {
        date = month = year = 0;
    }

    public int getDay() { return date; }
    public int getMonth() { return month; }
    public int getYear() { return year; }

    private String getMonthStr()
    {
        switch (month)
        {
            case 1: return "Jan";
            case 2: return "Feb";
            case 3: return "Mar";
            case 4: return "Apr";
            case 5: return "May";
            case 6: return "Jun";
            case 7: return "Jul";
            case 8: return "Aug";
            case 9: return "Sep";
            case 10: return "Oct";
            case 11: return "Nov";
            case 12: return "Dec";
        }
        return "?";
    }

    public String toString()
    {
        if (month == 0)
            return "-";

        String d = String.format("%2d", date);
        String m = getMonthStr();
        String y = String.format("%4d", year);
        return d + "/" + m + "/" + y;
    }
}
