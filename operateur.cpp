/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: operateur.cpp
 */

#include "operateur.h"

FactoryConstante fact; //cree factory

//fonctions class Operateur

void Operateur::opSWAP(Pile & p)
{
    int val1 = p.depiler()->getEntier();
    int val2 = p.depiler()->getEntier();

    Constante * temp = p.getTab(val1 - 1);
    p.setTab(val1 - 1, p.getTab(val2 - 1));
    p.setTab(val1 - 2, temp);
}

void Operateur::opSUM(Pile & p, QString mode, int com)
{
    int val1 = p.depiler()->getEntier();

    if (com == 0)
    {
        if (mode == "entier")
        {
            int sum = 0;
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getType() == "entier")
                    sum += p.getTab(i)->getEntier();
                if (p.getTab(i)->getType() == "reel")
                    sum += p.getTab(i)->getReel();
                if (p.getTab(i)->getType() == "rationnel")
                {
                    Constante * ration = p.getTab(i);
                    sum += ration->getNumerateur() / ration->getDenominateur();
                }
            }
            Constante * entier = fact.creeConstante("entier", sum);
            p.setTab(0, entier); //empiler le result a la premiere
        }

        if (mode == "reel")
        {
            float sum = 0;
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getType() == "entier")
                    sum += (float) p.getTab(i)->getEntier();
                if (p.getTab(i)->getType() == "reel")
                    sum += p.getTab(i)->getReel();
                if (p.getTab(i)->getType() == "rationnel")
                {
                    Constante * ration = p.getTab(i);
                    sum += (float) ration->getNumerateur() / (float) ration->getDenominateur();
                }
            }
            Constante * reel = fact.creeConstante("reel", 0, 0, sum);
            p.setTab(0, reel); //empiler le result a la premiere
        }

        if (mode == "ration")
        {
            Constante * ration = p.getTab(0);
            int num = ration->getNumerateur();
            int den = ration->getDenominateur();
            for (int i = 1; i < val1; i++)
            {
                ration = p.getTab(i);
                num = num * ration->getDenominateur() + den * ration->getNumerateur();
                den = den * ration->getDenominateur();
            }
            //simplifier
            int min = (num<=den ? num:den);
            for (int i = min; i > 1; i--)
            {
                if (num%i == 0 && den%i == 0)
                {
                    num /= i;
                    den /= i;
                }
            }

            Constante * rationn = fact.creeConstante("rationnel", num, den);
            p.setTab(0, rationn); //empiler le result a la premiere
        }
    }
    //complexe
    else
    {

        if (mode == "entier")
        {
            int sumR = 0, sumV = 0;
            //sum de partie reel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieReelle()->getType() == "entier")
                    sumR += p.getTab(i)->getPartieReelle()->getEntier();
                if (p.getTab(i)->getPartieReelle()->getType() == "reel")
                    sumR += p.getTab(i)->getPartieReelle()->getReel();
                if (p.getTab(i)->getPartieReelle()->getType() == "rationnel")
                    sumR += p.getTab(i)->getPartieReelle()->getNumerateur() / p.getTab(i)->getPartieReelle()->getDenominateur();
            }

            // sum de partie virtuel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieImaginaire()->getType() == "entier")
                    sumV += p.getTab(i)->getPartieImaginaire()->getEntier();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "reel")
                    sumV += p.getTab(i)->getPartieImaginaire()->getReel();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "rationnel")
                    sumV += p.getTab(i)->getPartieImaginaire()->getNumerateur() / p.getTab(i)->getPartieImaginaire()->getDenominateur();
            }

            Constante * re = fact.creeConstante("entier", sumR);
            Constante * vi = fact.creeConstante("entier", sumV);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, re, vi);
            p.setTab(0, complexe); // empiler le result a la premiere
        }

        if (mode == "reel")
        {
            float sumR = 0, sumV = 0;
            // sum de partie reel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieReelle()->getType() == "entier")
                    sumR += (float) p.getTab(i)->getPartieReelle()->getEntier();
                if (p.getTab(i)->getPartieReelle()->getType() == "reel")
                    sumR += p.getTab(i)->getPartieReelle()->getReel();
                if (p.getTab(i)->getPartieReelle()->getType() == "rationnel")
                    sumR += (float) p.getTab(i)->getPartieReelle()->getNumerateur() / (float) p.getTab(i)->getPartieReelle()->getDenominateur();
            }
            // sum de partie virtuel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieImaginaire()->getType() == "entier")
                    sumV += (float) p.getTab(i)->getPartieImaginaire()->getEntier();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "reel")
                    sumV += p.getTab(i)->getPartieImaginaire()->getReel();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "rationnel")
                    sumV += (float) p.getTab(i)->getPartieImaginaire()->getNumerateur() / (float) p.getTab(i)->getPartieImaginaire()->getDenominateur();
            }
            Constante * re = fact.creeConstante("reel", 0, 0, sumR);
            Constante * vi = fact.creeConstante("reel", 0, 0, sumV);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, re, vi);
            p.setTab(0, complexe); // empiler le result a la premiere

        }

        if (mode == "ration")
        {
            // tirer la partie reel et virtuel de complexe
            Constante * comp = p.getTab(0);
            Constante * reel = comp->getPartieReelle();
            Constante * virtuel = comp->getPartieImaginaire();

            // sum de partie reel
            int num = reel->getNumerateur();
            int den = reel->getDenominateur();
            for (int i = 1; i < val1; i++)
            {
                reel = p.getTab(i)->getPartieReelle();
                num = num * reel->getDenominateur() + den * reel->getNumerateur();
                den = den * reel->getDenominateur();
            }
            // simplifier
            int min = (num<=den ? num:den);
            for (int i = min; i > 1; i--)
            {
                if (num%i == 0 && den%i == 0)
                {
                    num /= i;
                    den /= i;
                }
            }

            Constante * re = fact.creeConstante("rationnel", num, den);

            // sum de partie virtuel
            num = virtuel->getNumerateur();
            den = virtuel->getDenominateur();
            for (int i = 1; i < val1; i++)
            {
                virtuel = p.getTab(i)->getPartieImaginaire();
                num = num * virtuel->getDenominateur() + den * virtuel->getNumerateur();
                den = den * virtuel->getDenominateur();
            }
            // simplifier
            min = (num<=den ? num:den);
            for (int i = min; i > 1; i--)
            {
                if (num%i == 0 && den%i == 0)
                {
                    num /= i;
                    den /= i;
                }
            }
            Constante * vi = fact.creeConstante("rationnel", num, den);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, re, vi);
            p.setTab(0, complexe); // empiler le result a la premiere
        }
    }
    int n = p.getN();
    int j = 1;

    for (int i = val1; i < n; i++)
        p.setTab(j++, p.getTab(i));

    for(int i = 0; i < n - j; i++)
        p.depiler();
}



void Operateur::opMEAN(Pile & p, QString mode, int com)
{
    int val1 = p.depiler()->getEntier();

    if (com == 0)
    {
        if (mode == "entier")
        {
            int sum = 0;
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getType() == "entier")
                    sum += p.getTab(i)->getEntier();
                if (p.getTab(i)->getType() == "reel")
                    sum += p.getTab(i)->getReel();
                if (p.getTab(i)->getType() == "rationnel")
                {
                    Constante * ration = p.getTab(i);
                    sum += ration->getNumerateur() / ration->getDenominateur();
                }
            }
            Constante * entier = fact.creeConstante("entier", sum / val1);
            p.setTab(0, entier); // empiler le result a la premiere
        }

        if (mode == "reel")
        {
            float sum = 0;
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getType() == "entier")
                    sum += (float) p.getTab(i)->getEntier();
                if (p.getTab(i)->getType() == "reel")
                    sum += p.getTab(i)->getReel();
                if (p.getTab(i)->getType() == "rationnel")
                {
                    Constante * ration = p.getTab(i);
                    sum += (float) ration->getNumerateur() / (float) ration->getDenominateur();
                }
            }
            Constante * reel = fact.creeConstante("reel", 0, 0, sum / val1);
            p.setTab(0, reel); // empiler le result a la premiere
       }

        if (mode == "ration")
        {
            Constante * ration = p.getTab(0);
            int num = ration->getNumerateur();
            int den = ration->getDenominateur();
            for (int i = 1; i < val1; i++)
            {
                ration = p.getTab(i);
                num = num * ration->getDenominateur() + den * ration->getNumerateur();
                den = den * ration->getDenominateur();
            }
            den *= val1;
            //simplifier
            int min = (num<=den ? num:den);
            for (int i = min; i > 1; i--)
            {
                if (num%i == 0 && den%i == 0)
                {
                    num /= i;
                    den /= i;
                }
            }

            Constante * rationn = fact.creeConstante("rationnel", num, den);
            p.setTab(0, rationn); // empiler le result a la premiere
        }
    }
    //complexe
    else
    {
        if (mode == "entier")
        {
            int sumR = 0, sumV = 0;
            // sum de partie reel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieReelle()->getType() == "entier")
                    sumR += p.getTab(i)->getPartieReelle()->getEntier();
                if (p.getTab(i)->getPartieReelle()->getType() == "reel")
                    sumR += p.getTab(i)->getPartieReelle()->getReel();
                if (p.getTab(i)->getPartieReelle()->getType() == "rationnel")
                    sumR += p.getTab(i)->getPartieReelle()->getNumerateur() / p.getTab(i)->getPartieReelle()->getDenominateur();
            }
            // sum de partie virtuel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieImaginaire()->getType() == "entier")
                    sumV += p.getTab(i)->getPartieImaginaire()->getEntier();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "reel")
                    sumV += p.getTab(i)->getPartieImaginaire()->getReel();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "rationnel")
                    sumV += p.getTab(i)->getPartieImaginaire()->getNumerateur() / p.getTab(i)->getPartieImaginaire()->getDenominateur();
            }
            Constante * re = fact.creeConstante("entier", sumR / val1);
            Constante * vi = fact.creeConstante("entier", sumV / val1);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, re, vi);
            p.setTab(0, complexe); // empiler le result a la premiere
        }

        if (mode == "reel")
        {
            float sumR = 0, sumV = 0;
            //sum de partie reel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieReelle()->getType() == "entier")
                    sumR += (float) p.getTab(i)->getPartieReelle()->getEntier();
                if (p.getTab(i)->getPartieReelle()->getType() == "reel")
                    sumR += p.getTab(i)->getPartieReelle()->getReel();
                if (p.getTab(i)->getPartieReelle()->getType() == "rationnel")
                    sumR += (float) p.getTab(i)->getPartieReelle()->getNumerateur() / (float) p.getTab(i)->getPartieReelle()->getDenominateur();
            }
            //sum de partie virtuel
            for (int i = 0; i < val1; i++)
            {
                if (p.getTab(i)->getPartieImaginaire()->getType() == "entier")
                    sumV += (float) p.getTab(i)->getPartieImaginaire()->getEntier();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "reel")
                    sumV += p.getTab(i)->getPartieImaginaire()->getReel();
                if (p.getTab(i)->getPartieImaginaire()->getType() == "rationnel")
                    sumV += (float) p.getTab(i)->getPartieImaginaire()->getNumerateur() / (float) p.getTab(i)->getPartieImaginaire()->getDenominateur();
            }
            Constante * re = fact.creeConstante("reel", 0, 0, sumR / val1);
            Constante * vi = fact.creeConstante("reel", 0, 0, sumV / val1);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, re, vi);
            p.setTab(0, complexe); // empiler le result a la premiere
        }

        if (mode == "ration")
        {
            // tirer la partie reel et virtuel de complexe
            Constante * comp = p.getTab(0);
            Constante * reel = comp->getPartieReelle();
            Constante * virtuel = comp->getPartieImaginaire();

            //sum de partie reel
            int num = reel->getNumerateur();
            int den = reel->getDenominateur();
            for (int i = 1; i < val1; i++)
            {
                reel = p.getTab(i)->getPartieReelle();
                num = num * reel->getDenominateur() + den * reel->getNumerateur();
                den = den * reel->getDenominateur();
            }
            den *= val1;
            //simplifier
            int min = (num<=den ? num:den);
            for (int i = min; i > 1; i--)
            {
                if (num%i == 0 && den%i == 0)
                {
                    num /= i;
                    den /= i;
                }
            }

            Constante * re = fact.creeConstante("rationnel", num, den);

            // sum de partie virtuel
            num = virtuel->getNumerateur();
            den = virtuel->getDenominateur();
            for (int i = 1; i < val1; i++)
            {
                virtuel = p.getTab(i)->getPartieImaginaire();
                num = num * virtuel->getDenominateur() + den * virtuel->getNumerateur();
                den = den * virtuel->getDenominateur();
            }
            den *= val1;
            // simplifier
            min = (num<=den ? num:den);
            for (int i = min; i > 1; i--)
            {
                if (num%i == 0 && den%i == 0)
                {
                    num /= i;
                    den /= i;
                }
            }
            Constante * vi = fact.creeConstante("rationnel", num, den);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, re, vi);
            p.setTab(0, complexe); // empiler le result a la premiere
        }
    }
    int n = p.getN();
    int j = 1;

    for (int i = val1; i < n; i++)
        p.setTab(j++, p.getTab(i));

    for (int i = 0; i < n - j; i++)
        p.depiler();
}



void Operateur::opDUP(Pile & p)
{
    p.setN(p.getN() + 1);

    for (int i = p.getN() - 1; i > 0; i--)
        p.setTab(i, p.getTab(i - 1));
}

void Operateur::opDROP(Pile & p)
{
    for (int i = 0; i < p.getN() - 1; i++)
        p.setTab(i, p.getTab(i + 1));
    p.setN(p.getN() - 1);
}

void Operateur::opPlus(Pile & p, QString mode, int com)
{

    if (com == 0)
    {
        //entier
        if (mode == "entier")
        {
            int val1 = 0, val2 = 0;
            //val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = (int) p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }
                // val2
                if (p.getTab(p.getN() - 1)->getType() == "entier")
                    val2 = p.depiler()->getEntier();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "reel")
                        val2 = (int) p.depiler()->getReel();
                    else
                        if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                        {
                            Constante * ration = p.depiler();
                            val2 = ration->getNumerateur() / ration->getDenominateur();
                        }
            Constante * entier = fact.creeConstante("entier", val1 + val2);
            p.empiler(entier);
        }
        //reelle
        if (mode == "reel")
        {
            float val1 = 0, val2 = 0;

            // val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }
            // val2
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val2 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val2 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val2 = ration->getNumerateur() / ration->getDenominateur();
                    }
            Constante * reel = fact.creeConstante("reel", 0, 0, val1 + val2);
            p.empiler(reel);
        }
        // rationnelle
        if (mode == "ration")
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();

            ration = p.depiler();
            int num2 = ration->getNumerateur();
            int den2 = ration->getDenominateur();

            num1 = num1 * den2 + num2 * den1;
            den1 = den1 * den2;

            // simplifier
            int min = (num1<=den1 ? num1:den1);
            for (int i = min; i > 1; i--)
            {
                if (num1%i == 0 && den1%i == 0)
                {
                    num1 /= i;
                    den1 /= i;
                }
            }

            Constante * rationn = fact.creeConstante("rationnel", num1, den1);
            p.empiler(rationn);
        }
    }
    // complexe
    else
    {
        Constante * comp = p.depiler();
        Constante * partieReel = comp->getPartieReelle();
        Constante * partieVir = comp->getPartieImaginaire();

        if (mode == "entier")
        {
            int reelVal1, virtuelVal1, reelVal2, virtuelVal2;

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = partieReel->getNumerateur() / partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = partieVir->getNumerateur() / partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal2 = partieReel->getNumerateur() / partieReel->getDenominateur();

            //partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal2 = partieVir->getNumerateur() / partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("entier", reelVal1 + reelVal2);
            Constante * virtuel = fact.creeConstante("entier", virtuelVal1 + virtuelVal2);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }

        if (mode == "reel")
        {
            float reelVal1, virtuelVal1, reelVal2, virtuelVal2;
            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal2 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal2 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("reel", 0, 0, reelVal1 + reelVal2);
            Constante * virtuel = fact.creeConstante("reel", 0, 0, virtuelVal1 + virtuelVal2);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }
        if (mode == "ration")
        {
            // partie reel
            int reelnum1 = partieReel->getNumerateur();
            int reelden1 = partieReel->getDenominateur();
            // partie virtuel
            int virtuelnum1 = partieVir->getNumerateur();
            int virtuelden1 = partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            int reelnum2 = partieReel->getNumerateur();
            int reelden2 = partieReel->getDenominateur();
            // partie virtuel
            int virtuelnum2 = partieVir->getNumerateur();
            int virtuelden2 = partieVir->getDenominateur();

            reelnum1 = reelnum1 * reelden2 + reelnum2 * reelden1;
            reelden1 = reelden1 * reelden2;

            // simplifier
            int min = (reelnum1<=reelden1 ? reelnum1:reelden1);
            for (int i = min; i > 1; i--)
            {
                if (reelnum1%i == 0 && reelden1%i == 0)
                {
                    reelnum1 /= i;
                    reelden1 /= i;
                }
            }

            virtuelnum1 = virtuelnum1 * virtuelden2 + virtuelnum2 * virtuelden1;
            virtuelden1 = virtuelden1 * virtuelden2;

            // simplifier
            min = (virtuelnum1<=virtuelden1 ? virtuelnum1:virtuelden1);
            for (int i = min; i > 1; i--)
            {
                if (virtuelnum1%i == 0 && virtuelden1%i == 0)
                {
                    virtuelnum1 /= i;
                    virtuelden1 /= i;
                }
            }

            Constante * reel = fact.creeConstante("rationnel", reelnum1, reelden1);
            Constante * virtuel = fact.creeConstante("rationnel", virtuelnum1, virtuelden1);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }
    }
}



void Operateur::opDim(Pile & p, QString mode, int com)
{
    if (com == 0)
    {
        // entier
        if (mode == "entier")
        {
            int val1 = 0, val2 = 0;

            // val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }
            // val2
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val2 = p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val2 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val2 = ration->getNumerateur() / ration->getDenominateur();
                    }
            Constante * entier = fact.creeConstante("entier", val2 - val1);
            p.empiler(entier);
        }
        // reelle
        if (mode == "reel")
        {
            float val1 = 0, val2 = 0;

            // val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }

            // val2
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val2 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val2 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val2 = ration->getNumerateur() / ration->getDenominateur();
                    }

            Constante * reel = fact.creeConstante("reel", 0, 0, val2 - val1);
            p.empiler(reel);
        }

        if (mode == "ration")
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();

            ration = p.depiler();
            int num2 = ration->getNumerateur();
            int den2 = ration->getDenominateur();

            num1 = num2 * den1 - num1 * den2;
            den1 = den1 * den2;

            // simplifier
            int min = (num1<=den1 ? num1:den1);
            for (int i = min; i > 1; i--)
            {
                if (num1%i == 0 && den1%i == 0)
                {
                    num1 /= i;
                    den1 /= i;
                }
            }

            Constante * rationn = fact.creeConstante("rationnel", num1, den1);
            p.empiler(rationn);
        }
    }
    else
    {
        // complexe
        Constante * comp = p.depiler();
        Constante * partieReel = comp->getPartieReelle();
        Constante * partieVir = comp->getPartieImaginaire();
        if (mode == "entier")
        {
            int reelVal1, virtuelVal1, reelVal2, virtuelVal2;
            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = partieReel->getNumerateur() / partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = partieVir->getNumerateur() / partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if(partieReel->getType()=="rationnel")
                reelVal2 = partieReel->getNumerateur() / partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal2 = partieVir->getNumerateur() / partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("entier", reelVal2 - reelVal1);
            Constante * virtuel = fact.creeConstante("entier", virtuelVal2 - virtuelVal1);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }

        if (mode == "reel")
        {
            float reelVal1, virtuelVal1, reelVal2, virtuelVal2;
            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal2 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal2 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("reel", 0, 0, reelVal2 - reelVal1);
            Constante * virtuel = fact.creeConstante("reel", 0, 0, virtuelVal2 - virtuelVal1);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }
        if (mode == "ration")
        {
            // partie reel
            int reelnum1 = partieReel->getNumerateur();
            int reelden1 = partieReel->getDenominateur();
            // partie virtuel
            int virtuelnum1 = partieVir->getNumerateur();
            int virtuelden1 = partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            int reelnum2 = partieReel->getNumerateur();
            int reelden2 = partieReel->getDenominateur();
            // partie virtuel
            int virtuelnum2 = partieVir->getNumerateur();
            int virtuelden2 = partieVir->getDenominateur();

            int reelnum = reelnum2 * reelden1 - reelnum1 * reelden2;
            int reelden = reelden1 * reelden2;

            // simplifier
            int min = (reelnum<=reelden ? reelnum:reelden);
            for (int i = min; i > 1; i--)
            {
                if (reelnum%i == 0 && reelden%i == 0)
                {
                    reelnum /= i;
                    reelden /= i;
                }
            }

            int virtuelnum = virtuelnum2 * virtuelden1 - virtuelnum1 * virtuelden2;
            int virtuelden = virtuelden1 * virtuelden2;

            // simplifier
            min = (virtuelnum<=virtuelden ? virtuelnum:virtuelden);
            for (int i = min; i > 1; i--)
            {
                if (virtuelnum%i == 0 && virtuelden%i == 0)
                {
                    virtuelnum /= i;
                    virtuelden /= i;
                }
            }

            Constante * reel = fact.creeConstante("rationnel", reelnum, reelden);
            Constante * virtuel = fact.creeConstante("rationnel", virtuelnum, virtuelden);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }
    }
}

void Operateur::opMult(Pile & p, QString mode, int com)
{
    if (com == 0)
    {
        // entier
        if (mode == "entier")
        {
            int val1 = 0, val2 = 0;

            // val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }

            // val2
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val2 = p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val2 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val2 = ration->getNumerateur() / ration->getDenominateur();
                    }

            Constante * entier = fact.creeConstante("entier", val2 * val1);
            p.empiler(entier);
        }

        // reelle
        if (mode == "reel")
        {
            float val1 = 0, val2 = 0;

            // val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }
            // val2
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val2 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val2 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val2 = ration->getNumerateur() / ration->getDenominateur();
                    }
            Constante * reel = fact.creeConstante("reel", 0, 0, val2 * val1);
            p.empiler(reel);
        }

        // rationnelle
        if (mode == "ration")
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();

            ration = p.depiler();
            int num2 = ration->getNumerateur();
            int den2 = ration->getDenominateur();

            num1 = num1 * num2;
            den1 = den1 * den2;

            // simplifier
            int min = (num1<=den1 ? num1:den1);
            for (int i = min; i > 1; i--)
            {
                if (num1%i == 0 && den1%i == 0)
                {
                    num1 /= i;
                    den1 /= i;
                }
            }

            Constante * rationn = fact.creeConstante("rationnel", num1, den1);
            p.empiler(rationn);
        }
    }
    else
    {
        // complexe
        Constante * comp = p.depiler();
        Constante * partieReel = comp->getPartieReelle();
        Constante * partieVir = comp->getPartieImaginaire();
        if (mode == "entier")
        {
            int reelVal1, virtuelVal1, reelVal2, virtuelVal2;
            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = partieReel->getNumerateur() / partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = partieVir->getNumerateur() / partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal2 = partieReel->getNumerateur() / partieReel->getDenominateur();

            //partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal2 = partieVir->getNumerateur() / partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("entier", reelVal1 * reelVal2 - virtuelVal1 * virtuelVal2);
            Constante * virtuel = fact.creeConstante("entier", reelVal1 * virtuelVal2 + reelVal2 * virtuelVal1);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }

        if (mode == "reel")
        {
            float reelVal1, virtuelVal1, reelVal2, virtuelVal2;
            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal2 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal2 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("reel", 0, 0, reelVal1 * reelVal2 - virtuelVal1 * virtuelVal2);
            Constante * virtuel = fact.creeConstante("reel", 0, 0, reelVal1 * virtuelVal2 + reelVal2 * virtuelVal1);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }

        if (mode == "ration")
        {
            // partie reel
            int reelnum1 = partieReel->getNumerateur();
            int reelden1 = partieReel->getDenominateur();
            // partie virtuel
            int virtuelnum1 = partieVir->getNumerateur();
            int virtuelden1 = partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            int reelnum2 = partieReel->getNumerateur();
            int reelden2 = partieReel->getDenominateur();
            // partie virtuel
            int virtuelnum2 = partieVir->getNumerateur();
            int virtuelden2 = partieVir->getDenominateur();

            int reelnum = reelnum1 * reelnum2 * virtuelden1 * virtuelden2 - reelden1 * reelden2 * virtuelnum1 * virtuelnum2;
            int reelden = reelden1 * reelden2 * virtuelden1 * virtuelden2;

            // simplifier
            int min = (reelnum<=reelden ? reelnum:reelden);
            for (int i = min; i > 1; i--)
            {
                if (reelnum%i == 0 && reelden%i == 0)
                {
                    reelnum /= i;
                    reelden /= i;
                }
            }

            int virtuelnum = reelnum1 * virtuelnum2 * virtuelden1 * reelden2 + reelden1 * virtuelden2 * virtuelnum1 * reelnum2;
            int virtuelden = reelden1 * reelden2 * virtuelden1 * virtuelden2;

            // simplifier
            min = (virtuelnum<=virtuelden ? virtuelnum:virtuelden);
            for (int i = min; i > 1; i--)
            {
                if (virtuelnum%i == 0 && virtuelden%i == 0)
                {
                    virtuelnum /= i;
                    virtuelden /= i;
                }
            }

            Constante * reel = fact.creeConstante("rationnel", reelnum, reelden);
            Constante * virtuel = fact.creeConstante("rationnel", virtuelnum, virtuelden);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }
    }
}

void Operateur::opDiv(Pile & p, QString mode, int com)
{
    if (com == 0)
    {
        // entier
        if (mode == "entier")
        {
            int val1 = 0, val2 = 0;

            // val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }
            // val2
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val2 = p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val2 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val2 = ration->getNumerateur() / ration->getDenominateur();
                    }
            Constante * entier = fact.creeConstante("entier", val2 / val1);
            p.empiler(entier);
        }
        // reelle
        if (mode == "reel")
        {
            float val1 = 0, val2 = 0;

            // val1
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val1 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val1 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val1 = ration->getNumerateur() / ration->getDenominateur();
                    }

            // val2
            if (p.getTab(p.getN() - 1)->getType() == "entier")
                val2 = (float) p.depiler()->getEntier();
            else
                if (p.getTab(p.getN() - 1)->getType() == "reel")
                    val2 = p.depiler()->getReel();
                else
                    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                    {
                        Constante * ration = p.depiler();
                        val2 = ration->getNumerateur() / ration->getDenominateur();
                    }
            Constante * reel = fact.creeConstante("reel", 0, 0, val2 / val1);
            p.empiler(reel);
        }
        // rationnelle
        if (mode == "ration")
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();

            ration = p.depiler();
            int num2 = ration->getNumerateur();
            int den2 = ration->getDenominateur();

            num2 = num2 * den1;
            den2 = den2 * num1;

            // simplifier
            int min = (num2<=den2 ? num2:den2);
            for (int i = min; i > 1; i--)
            {
                if (num2%i == 0 && den2%i == 0)
                {
                    num2 /= i;
                    den2 /= i;
                }
            }
            Constante * rationn = fact.creeConstante("rationnel", num2, den2);
            p.empiler(rationn);
        }
    }
    else
    {
        // complexe
        Constante * comp = p.depiler();
        Constante * partieReel = comp->getPartieReelle();
        Constante * partieVir = comp->getPartieImaginaire();
        if (mode == "entier")
        {
            int reelVal1, virtuelVal1, reelVal2, virtuelVal2;
            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = partieReel->getNumerateur() / partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = partieVir->getNumerateur() / partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal2 = partieReel->getNumerateur() / partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = partieVir->getEntier();

            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();

            if (partieVir->getType() == "rationnel")
                virtuelVal2 = partieVir->getNumerateur() / partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("entier", (reelVal2 * reelVal1 + virtuelVal2 * virtuelVal1) / (virtuelVal2 * virtuelVal2 + virtuelVal1 * virtuelVal1));
            Constante * virtuel = fact.creeConstante("entier", (virtuelVal1 * reelVal2 - virtuelVal2 * reelVal1) / (virtuelVal2 * virtuelVal2 + virtuelVal1 * virtuelVal1));
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }

        if (mode == "reel")
        {
            float reelVal1, virtuelVal1, reelVal2, virtuelVal2;
            // partie reel
            if (partieReel->getType() == "entier")
                reelVal1 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal1 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal1 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal1 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal1 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal1 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            if (partieReel->getType() == "entier")
                reelVal2 = (float) partieReel->getEntier();
            if (partieReel->getType() == "reel")
                reelVal2 = partieReel->getReel();
            if (partieReel->getType() == "rationnel")
                reelVal2 = (float) partieReel->getNumerateur() / (float) partieReel->getDenominateur();

            // partie virtuel
            if (partieVir->getType() == "entier")
                virtuelVal2 = (float) partieVir->getEntier();
            if (partieVir->getType() == "reel")
                virtuelVal2 = partieVir->getReel();
            if (partieVir->getType() == "rationnel")
                virtuelVal2 = (float) partieVir->getNumerateur() / (float) partieVir->getDenominateur();

            Constante * reel = fact.creeConstante("reel", 0, 0, (reelVal2 * reelVal1 + virtuelVal2 * virtuelVal1) / (virtuelVal2 * virtuelVal2 + virtuelVal1 * virtuelVal1));
            Constante * virtuel = fact.creeConstante("reel", 0, 0,(virtuelVal1 * reelVal2 - virtuelVal2 * reelVal1) / (virtuelVal2 * virtuelVal2 + virtuelVal1 * virtuelVal1));
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }
        if (mode == "ration")
        {
            // partie reel
            int reelnum1 = partieReel->getNumerateur();
            int reelden1 = partieReel->getDenominateur();
            // partie virtuel
            int virtuelnum1 = partieVir->getNumerateur();
            int virtuelden1 = partieVir->getDenominateur();

            // deuxieme constante
            comp = p.depiler();
            partieReel = comp->getPartieReelle();
            partieVir = comp->getPartieImaginaire();

            // partie reel
            int reelnum2 = partieReel->getNumerateur();
            int reelden2 = partieReel->getDenominateur();

            // partie virtuel
            int virtuelnum2 = partieVir->getNumerateur();
            int virtuelden2 = partieVir->getDenominateur();

            int reelnum = reelnum1 * reelnum2 * virtuelden1 * virtuelden2 * virtuelden2 * reelden2 + reelden1 * reelden2 * reelden2 * virtuelden2 * virtuelnum1 * virtuelnum2;
            int reelden = reelden1 * virtuelden1 * reelnum2 * reelnum2 * virtuelden2 * virtuelden2 + reelden1 * virtuelden1 * reelden2 * reelden2 * virtuelnum2 * virtuelnum2;

            // simplifier
            int min = (reelnum<=reelden ? reelnum:reelden);
            for (int i = min; i > 1; i--)
            {
                if (reelnum%i == 0 && reelden%i == 0)
                {
                    reelnum /= i;
                    reelden /= i;
                }
            }

            int virtuelnum = virtuelnum1 * reelnum2 * reelden1 * virtuelden2 * virtuelden2 * reelden2 - reelnum1 * virtuelnum2 * virtuelden1 * virtuelden2 * reelden2 * reelden2;
            int virtuelden = virtuelden1 * reelden1 * reelnum2 * reelnum2 * virtuelden2 * virtuelden2 + virtuelden1 * reelden1 * reelden2 * reelden2 * virtuelnum2 * virtuelnum2;

            // simplifier
            min = (virtuelnum<=virtuelden ? virtuelnum:virtuelden);
            for (int i = min; i > 1; i--)
            {
                if (virtuelnum%i == 0 && virtuelden%i == 0)
                {
                    virtuelnum /= i;
                    virtuelden /= i;
                }
            }

            Constante * reel = fact.creeConstante("rationnel", reelnum, reelden);
            Constante * virtuel = fact.creeConstante("rationnel", virtuelnum, virtuelden);
            Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
            p.empiler(complexe);
        }
    }
}

void Operateur::opFact(Pile & p)
{
    // verifier si le type est entier
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
         int val1 = p.depiler()->getEntier();
         int val2 = 1;
         for (int i = 1; i <= val1; i++)
             val2 *= i;
         Constante * entier = fact.creeConstante("entier", val2);
         p.empiler(entier);
    }
    else
    {
        // expression l'erreur
        QMessageBox message;
        message.setText("La valeur n'est pas entier");
        message.exec();
    }
}

void Operateur::opSin(Pile & p, QString type)
{
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1;
        if (type == "rad")
            val1 = p.depiler()->getEntier();
        if (type == "deg")
            val1 = PI * p.depiler()->getEntier() / 180;
        float val2 = sin(val1);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1;
            if (type == "rad")
                val1 = p.depiler()->getReel();
            if (type == "deg")
                val1 = PI * p.depiler()->getReel() / 180;
            float val2 = sin(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;
            // si type==rad, change rien
            if (type == "deg")
                val1 = PI * val1 / 180;
            float val2 = sin(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opCos(Pile & p, QString type)
{
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1;
        if (type == "rad")
            val1 = p.depiler()->getEntier();
        if (type == "deg")
            val1 = PI * p.depiler()->getEntier() / 180;
        float val2 = cos(val1);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1;
            if (type == "rad")
                val1 = p.depiler()->getReel();
            if (type == "deg")
                val1 = PI * p.depiler()->getReel() / 180;
            float val2 = cos(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;
            // si type==rad, change rien
            if (type == "deg")
                val1 = PI * val1 / 180;
            float val2 = cos(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opTan(Pile & p, QString type)
{
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1;
        if (type == "rad")
            val1 = p.depiler()->getEntier();
        if (type == "deg")
            val1 = PI * p.depiler()->getEntier() / 180;
        float val2 = tan(val1);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1;
            if (type == "rad")
                val1 = p.depiler()->getReel();
            if (type == "deg")
                val1 = PI * p.depiler()->getReel() / 180;
            float val2 = tan(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;
            // si type==rad, change rien
            if (type == "deg")
                val1 = PI * val1 / 180;
            float val2 = tan(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opSinh(Pile & p, QString type)
{
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1;
        if (type == "rad")
            val1 = p.depiler()->getEntier();
        if (type == "deg")
            val1 = PI * p.depiler()->getEntier() / 180;
        float val2 = sinh(val1);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1;
            if (type == "rad")
                val1 = p.depiler()->getReel();
            if (type == "deg")
                val1 = PI * p.depiler()->getReel() / 180;
            float val2 = sinh(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;
            // si type==rad, change rien
            if (type == "deg")
                val1 = PI * val1 / 180;
            float val2 = sinh(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opCosh(Pile & p, QString type)
{
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1;
        if (type == "rad")
            val1 = p.depiler()->getEntier();
        if (type == "deg")
            val1 = PI * p.depiler()->getEntier() / 180;
        float val2 = cosh(val1);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1;
            if (type == "rad")
                val1 = p.depiler()->getReel();
            if (type == "deg")
                val1 = PI * p.depiler()->getReel() / 180;
            float val2 = cosh(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;
            // si type==rad, change rien
            if (type=="deg")
                val1 = PI * val1 / 180;
            float val2 = cosh(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opTanh(Pile & p, QString type)
{
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1;
        if (type == "rad")
            val1 = p.depiler()->getEntier();
        if (type == "deg")
            val1 = PI * p.depiler()->getEntier() / 180;
        float val2 = tanh(val1);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1;
            if (type == "rad")
                val1 = p.depiler()->getReel();
            if (type == "deg")
                val1 = PI * p.depiler()->getReel() / 180;
            float val2 = tanh(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;
            // si type==rad, change rien
            if (type == "deg")
                val1 = PI * val1 / 180;
            float val2 = tanh(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opLog(Pile & p)
{
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1 = p.depiler()->getEntier();
        float val2 = log(val1) / log(10.0);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1 = p.depiler()->getReel();
            float val2 = log(val1) / log(10.0);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;

            float val2 = log(val1) / log(10.0);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opLn(Pile & p){
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        double val1 = p.depiler()->getEntier();
        float val2 = log(val1);
        Constante * reel = fact.creeConstante("reel", 0, 0, val2);
        p.empiler(reel);
    }
    else
        if (p.getTab(p.getN() - 1)->getType() == "reel")
        {
            double val1 = p.depiler()->getReel();
            float val2 = log(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
        else
        {
            Constante * ration = p.depiler();
            int num1 = ration->getNumerateur();
            int den1 = ration->getDenominateur();
            double val1 = (float) num1 / den1;

            float val2 = log(val1);
            Constante * reel = fact.creeConstante("reel", 0, 0, val2);
            p.empiler(reel);
        }
}

void Operateur::opPOW(Pile & p, QString mode)
{
    // entier
    if (mode == "entier")
    {
        int val1 = 0, val2 = 0;

        // val1
        if (p.getTab(p.getN() - 1)->getType() == "entier")
            val1 = p.depiler()->getEntier();
        else
            if (p.getTab(p.getN() - 1)->getType() == "reel")
                val1 = (int) p.depiler()->getReel();
            else
                if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                {
                    Constante * ration = p.depiler();
                    val1 = ration->getNumerateur() / ration->getDenominateur();
                }
        // val2
        if (p.getTab(p.getN() - 1)->getType() == "entier")
            val2 = p.depiler()->getEntier();
        else
            if (p.getTab(p.getN() - 1)->getType() == "reel")
                val2 = (int) p.depiler()->getReel();
            else
                if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                {
                    Constante * ration = p.depiler();
                    val2 = ration->getNumerateur() / ration->getDenominateur();
                }
        int res = 1;
        for (int i = 0; i < val1; i++)
            res *= val2;

         Constante * entier = fact.creeConstante("entier", res);
         p.empiler(entier);
    }
    // reelle
    if (mode == "reel")
    {
        int val1 = 0;
        float val2 = 0;

        // val1
        if (p.getTab(p.getN() - 1)->getType() == "entier")
            val1 = p.depiler()->getEntier();
        else
            if (p.getTab(p.getN() - 1)->getType() == "reel")
                val1 = (int) p.depiler()->getReel();
            else
                if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                {
                    Constante * ration = p.depiler();
                    val1 = ration->getNumerateur() / ration->getDenominateur();
                }
        // val2
        if (p.getTab(p.getN() - 1)->getType() == "entier")
            val2 = (float) p.depiler()->getEntier();
        else
            if (p.getTab(p.getN() - 1)->getType() == "reel")
                val2 = p.depiler()->getReel();
            else
                if (p.getTab(p.getN() - 1)->getType() == "rationnel")
                {
                    Constante * ration = p.depiler();
                    val2 = (float) ration->getNumerateur() / (float) ration->getDenominateur();
                }
        float res = 1;
        for(int i = 0; i < val1; i++)
            res *= val2;

         Constante * reel = fact.creeConstante("reel", 0, 0, res);
         p.empiler(reel);
    }
    // rationnelle
    if (mode == "ration")
    {
        Constante * ration = p.depiler();
        int val1 = ration->getNumerateur() / ration->getDenominateur();

        ration = p.depiler();

        int num1 = ration->getNumerateur();
        int den1 = ration->getDenominateur();

        int resn = 1;
        int resd = 1;
        for (int i = 0; i < val1; i++)
        {
            resn *= num1;
            resd *= den1;
        }

        // simplifier
        int min = (resn<=resd ? resn:resd);
        for (int i = min; i > 1; i--)
        {
            if (resn%i == 0 && resd%i == 0)
            {
                resn /= i;
                resd /= i;
            }
        }
         Constante * rationn = fact.creeConstante("rationnel", resn, resd);
         p.empiler(rationn);
    }
}

void Operateur::opMOD(Pile & p)
{
    // verifier si le type est entier
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
         int val1 = p.depiler()->getEntier();
         int val2 = p.depiler()->getEntier();;
         val2 = val2 % val1;
         Constante * entier = fact.creeConstante("entier", val2);
         p.empiler(entier);
    }
    else
    {
        // expression l'erreur
        QMessageBox message;
        message.setText("La valeur n'est pas entier");
        message.exec();
    }
}

void Operateur::opSIGN(Pile & p)
{
    // entier
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        int val = (-1) * p.depiler()->getEntier();
        Constante * entier = fact.creeConstante("entier", val);
        p.empiler(entier);
    }
    // reel
    if (p.getTab(p.getN() - 1)->getType() == "reel")
    {
        float val = (-1) * p.depiler()->getReel();
        Constante * reel = fact.creeConstante("reel", 0, 0, val);
        p.empiler(reel);
    }
    // rationnelle
    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
    {
        Constante * ration = p.depiler();
        int num = (-1) * ration->getNumerateur();
        int den = ration->getDenominateur();
        Constante * rationn = fact.creeConstante("rationnel", num, den);
        p.empiler(rationn);
    }
    // complexe
    if (p.getTab(p.getN() - 1)->getType() == "complexe")
    {
        Constante * comp = p.depiler();
        Constante * reel;
        Constante * virtuel;
        // dans la partie reel
        if (comp->getPartieReelle()->getType() == "entier")
        {
            int val = (-1) * comp->getPartieReelle()->getEntier();
            reel = fact.creeConstante("entier", val);
        }

        if (comp->getPartieReelle()->getType() == "reel")
        {
            float val = (-1) * comp->getPartieReelle()->getReel();
            reel = fact.creeConstante("reel", 0, 0, val);
        }

        if (comp->getPartieReelle()->getType() == "rationnel")
        {
            int num = (-1) * comp->getPartieReelle()->getNumerateur();
            int den = comp->getPartieReelle()->getDenominateur();
            reel = fact.creeConstante("rationnel", num, den);
        }

        // dans la partie virtuel
        if (comp->getPartieImaginaire()->getType() == "entier")
        {
            int val = (-1) * comp->getPartieImaginaire()->getEntier();
            virtuel = fact.creeConstante("entier", val);
        }

        if (comp->getPartieImaginaire()->getType() == "reel")
        {
            float val = (-1) * comp->getPartieImaginaire()->getReel();
            virtuel = fact.creeConstante("reel", 0, 0, val);
        }

        if (comp->getPartieImaginaire()->getType() == "rationnel")
        {
            int num = (-1) * comp->getPartieImaginaire()->getNumerateur();
            int den = comp->getPartieImaginaire()->getDenominateur();
            virtuel = fact.creeConstante("rationnel", num, den);
        }

        Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, reel, virtuel);
        p.empiler(complexe);
    }
}

void Operateur::opINV(Pile & p)
{
    // entier
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        int val = 1 / p.depiler()->getEntier();
        Constante * entier = fact.creeConstante("entier", val);
        p.empiler(entier);
    }
    // reel
    if (p.getTab(p.getN() - 1)->getType() == "reel")
    {
        float val = 1 / p.depiler()->getReel();
        Constante * reel = fact.creeConstante("reel", 0, 0, val);
        p.empiler(reel);
    }
    // rationnelle
    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
    {
        Constante * ration = p.depiler();
        int den = ration->getNumerateur();
        int num = ration->getDenominateur();
        Constante * rationn = fact.creeConstante("rationnel", num, den);
        p.empiler(rationn);
    }
}

void Operateur::opSQRT(Pile & p)
{
    // entier
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        int val = sqrt(p.depiler()->getEntier());
        Constante * entier = fact.creeConstante("entier", val);
        p.empiler(entier);
    }
    // reel
    if (p.getTab(p.getN() - 1)->getType() == "reel")
    {
        float val = sqrt(p.depiler()->getReel());
        Constante * reel = fact.creeConstante("reel", 0, 0, val);
        p.empiler(reel);
    }
    // rationnelle
    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
    {
        Constante * ration = p.depiler();
        int num = sqrt(ration->getNumerateur());
        int den = sqrt(ration->getDenominateur());
        Constante * rationn = fact.creeConstante("rationnel", num, den);
        p.empiler(rationn);
    }
}

void Operateur::opSQR(Pile & p)
{
    // entier
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        int val = p.depiler()->getEntier();
        Constante * entier = fact.creeConstante("entier", val * val);
        p.empiler(entier);
    }
    // reel
    if (p.getTab(p.getN() - 1)->getType() == "reel")
    {
        float val = p.depiler()->getReel();
        Constante * reel = fact.creeConstante("reel", 0, 0, val * val);
        p.empiler(reel);
    }
    // rationnelle
    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
    {
        Constante * ration = p.depiler();
        int num = ration->getNumerateur();
        int den = ration->getDenominateur();
        Constante * rationn = fact.creeConstante("rationnel", num * num, den * den);
        p.empiler(rationn);
    }
    // complexe
    if (p.getTab(p.getN() - 1)->getType() == "complexe")
    {
        Constante * comp = p.depiler();
        Constante * reel = comp->getPartieReelle();
        Constante * virtuel = comp->getPartieImaginaire();
        int vReel = reel->getEntier();
        int vVirtuel = virtuel->getEntier();
        int resReel = vReel * vReel - vVirtuel * vVirtuel;
        int resVirtuel = 2 * vReel * vVirtuel;
        Constante * r = fact.creeConstante("entier", resReel);
        Constante * v = fact.creeConstante("entier", resVirtuel);
        Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, r, v);
        p.empiler(complexe);
    }

}

void Operateur::opCUBE(Pile & p)
{
    // entier
    if (p.getTab(p.getN() - 1)->getType() == "entier")
    {
        int val = p.depiler()->getEntier();
        Constante * entier = fact.creeConstante("entier", val * val * val);
        p.empiler(entier);
    }
    // reel
    if (p.getTab(p.getN() - 1)->getType() == "reel")
    {
        float val = p.depiler()->getReel();
        Constante * reel = fact.creeConstante("reel", 0, 0, val * val * val);
        p.empiler(reel);
    }
    // rationnelle
    if (p.getTab(p.getN() - 1)->getType() == "rationnel")
    {
        Constante * ration = p.depiler();
        int num = ration->getNumerateur();
        int den = ration->getDenominateur();
        Constante * rationn = fact.creeConstante("rationnel", num * num * num, den * den * den);
        p.empiler(rationn);
    }
    // complexe
    if (p.getTab(p.getN() - 1)->getType() == "complexe")
    {
        Constante * comp = p.depiler();
        Constante * reel = comp->getPartieReelle();
        Constante * virtuel = comp->getPartieImaginaire();
        int vReel = reel->getEntier();
        int vVirtuel = virtuel->getEntier();
        int resReel = vReel * vReel * vReel - 3 * vReel * vVirtuel * vVirtuel;
        int resVirtuel = 3 * vReel * vReel * vVirtuel - vVirtuel * vVirtuel * vVirtuel;
        Constante * r = fact.creeConstante("entier", resReel);
        Constante * v = fact.creeConstante("entier", resVirtuel);
        Constante * complexe = fact.creeConstante("complexe", 0, 0, 0, r, v);
        p.empiler(complexe);
    }
}
