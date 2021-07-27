public class Hospital {
    private String name;
    private Date date_admission;
    private String disease;
    private Date date_discharge;

    public Hospital(String name, Date date_admission, String disease, Date date_discharge)
    {
        this.name = name;
        this.date_admission = date_admission;
        this.disease = disease;
        this.date_discharge = date_discharge;
    }

    public String getName() { return name; }
    public String getDateAdmission() { return date_admission.toString(); }
    public String getDisease() { return disease; }
    public String getDateDischarge() { return date_discharge.toString(); }

    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
