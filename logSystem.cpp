/*!
  * \file logSystem.h
  * \author Han Jia & Antoine Hars
  * \brief Déclaration des méthodes de la classe LogSystem.
  * Ce fichier contient la déclaration des méthodes de la classe LogSystem.
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: logSystem.h
 */

#include "logSystem.h"

/*!
 *  \brief Fonction permetant d'ajouter un message de log.
 *  Fonction permetant d'ajouter un message de log.
 *  \param log log a gérer.
 */
void LogSystem::add(LogMessage log)
{

    QFile fichier("log.txt");
    fichier.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream flux(&fichier);

    QString tmp = log.toString().c_str();
    flux<<tmp<<"\n";
    std::cout<<log.toString()<<"\n";
    fichier.close();
}

/*!
 *  \brief Fonction permetant d'ajouter un message de log.
 *  Fonction permetant d'ajouter un message de log.
 *  \param msg Message a gérer.
 *  \param criticite Criticite du message.
 */
void LogSystem::add(QString msg, unsigned int criticite)
{
    add(LogMessage(msg, criticite));
}
