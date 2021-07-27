public class PotentialGene 
{

    public static boolean isPotentialGene(String dna)
    {
        if (!dna.startsWith("ATG"))
            return false;
        if (dna.length() % 3 != 0)
            return false;
        String[] stopCodons = { "TAG", "TAA", "TGA" };
        boolean endCodon = false;

        for (String e : stopCodons)
        {
            if (dna.contains(e))
            {
                String dnaS = dna.substring(0, dna.length() - 3);
                if (!dnaS.contains(e))
                {
                    endCodon = true;
                    break;
                }
                return false;
            }
        }
        if (!endCodon)
            return false;
        return true;
    }

    public static void main(String[] args)
    {
        if (!Util.argMatch(args, 1))
            return;

        String dna = args[0].toUpperCase();
        if (isPotentialGene(dna))
            System.out.println(dna + " is a potential gene.");
        else
            System.out.println(dna + " is not a potential gene.");
    }
}
