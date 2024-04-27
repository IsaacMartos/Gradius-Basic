#include "ScoreManager.h"
#include <string>

ScoreManager* ScoreManager::instance = nullptr;

ScoreManager* ScoreManager::GetInstance() {
    if (instance == nullptr) {
        instance = new ScoreManager();
    }
    return instance;
}

int ScoreManager::AddPoints(int pointsToAdd)
{
    punctuation += pointsToAdd;
    return  punctuation;
}

int ScoreManager::SubstractPoints(int pointsToSubstract)
{
    punctuation -= pointsToSubstract;
    return  punctuation;
}

int ScoreManager::SetNewRecord(int newRecord)
{
	if (punctuation >= record)
	{
        record = punctuation;
	}
	else if (newRecord > record)
	{
        record = newRecord;
	}
    return record;
}

int ScoreManager::SetPoints(int points)
{
    punctuation = points;
    return points;
}

int ScoreManager::GetPoints()
{
    return punctuation;
}

int ScoreManager::GetRecord()
{
    return record;
}

void ScoreManager::SaveToFile(const std::string& filename) 
{
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Record: " << record;
        file.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar el récord." << std::endl;
    }
}

void ScoreManager::LoadFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Suponiendo que el archivo tiene el formato "Record: <valor>"
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string recordStr = line.substr(pos + 1);
                record = std::stoi(recordStr);
            }
        }
        file.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para cargar el récord." << std::endl;
    }
}

