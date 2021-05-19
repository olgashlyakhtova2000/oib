
#include <iostream>
#include <vector>

using namespace std;

string rus = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
int sizeCube = 6;
string removeNotusuful(string message) //оставляем лишь буквы и меняем их на прописные
{
    string newText = "";
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == 'я' or message[i] == 'я') newText += 'Я';
        for (int j = 0; j < rus.size(); j++)
        {
            if ((unsigned char)(toupper(message[i])) == (unsigned char)rus[j])
                newText += (unsigned char)(toupper(message[i]));
        }
    }
    return newText;
}
string getAlf(string key) //новый алфавит из ключевой фразы
{
    for (int i = 192; i < 223; i++)
    {
        if (i == 198)
            key += 'Ё';
        key += (unsigned char)i;
    }
    string resultStr = "";

    resultStr += key[0];

    for (int i = 0; i < key.size(); i++)
    {
        if (resultStr.find(key[i], 1) == 4294967295)
            resultStr += key[i];
    }
    resultStr.erase(0, 1);
    return resultStr;
}
vector<string> getCube(string key)
{
    vector <string> cube;
    key = removeNotusuful(key);
    key = getAlf(key);
    int count = 0;
    for (int i = 0; i < sizeCube; i++)
    {
        string str = "";
        for (int j = 0; j < sizeCube; j++)
        {
            if (j + sizeCube * i < key.size() - 1)
                str += key[j + sizeCube * i];
            else {

                str += (unsigned char)48 + count;
                count++;
            }
        }
        cube.push_back(str);
    }
    
    return cube;
}
string Encrypt(string text, string key)
{
    vector <string> cube = getCube(key);

    text = removeNotusuful(text);

    vector<int> rows;
    vector<int> columns;

    for (int i = 0; i < text.size(); i++)
    {
        for (int j = 0; j < sizeCube; j++)
        {
            if (cube[j].find(text[i]) != 4294967295)
            {
                rows.push_back(j);
                for (int h = 0; h < sizeCube; h++)
                    if (cube[j][h] == text[i])
                    {
                        columns.push_back(h);
                        cout << j << " " << h << endl;
                    }
            }
        }
    }
    //for (int i = 0; i < rows.size(); i++)
    //    cout << rows[i] << " ";
    //cout << endl;
    //for (int i = 0; i < rows.size(); i++)
    //    cout << columns[i] << " "; 
    string encryptMessage = "";
    for (int i = 0; i < rows.size() - 2; i += 2)
        encryptMessage += cube[rows[i]][rows[i + 1]];
    for (int i = 0; i < columns.size() - 2; i += 2)
        encryptMessage += cube[columns[i]][columns[i + 1]];
    cout << endl;
    return encryptMessage;
}
string Decrypt(string text, string key)
{
    string decrMes = "";
    vector <string> cube = getCube(key);

    vector<int> rows;
    vector<int> columns;

    for (int i = 0; i < text.size(); i++)
    {
        for (int j = 0; j < sizeCube; j++)
        {
            if (cube[j].find(text[i]) != 4294967295)
            {
                rows.push_back(j);
                for (int h = 0; h < sizeCube; h++)
                    if (cube[j][h] == text[i])
                    {
                        cout << j << " " << h << endl;
                        columns.push_back(h);
                    }
            }
        }
    }
    for (int i = 0; i < rows.size(); i++)
        cout << rows[i] << " ";
    cout << endl;
    for (int i = 0; i < rows.size(); i++)
        cout << columns[i] << " ";
    return decrMes;
}
int main()
{
    setlocale(0, "RUS");
    string key = "Вздыхать и думать про себя: \nКогда же черт возьмет тебя!";
    string text = "Как в просвещенной Европе, так и в просвещенной России есть теперь весьма много почтенных людей, которые без того не могут покушать в трактире, чтоб не поговорить с слугою, а иногда даже забавно пошутить над ним. Впрочем, приезжий делал не всё пустые вопросы; он с чрезвычайною точностию расспросил, кто в городе губернатор, кто председатель палаты, кто прокурор.";

    cout << text << endl;
    //cout << Encrypt(text, key) << endl;
    cout << Decrypt(Encrypt(text, key), key) << endl;
   /* cout << endl;
    cout << text << endl;
    for (int i = 0; i < sizeCube; i++)
    {
        cout << cube[i] << endl;
    }
    for (int i = 0; i < rows.size(); i++)
        cout << rows[i]<< " ";
    cout << endl;
    for (int i = 0; i < rows.size(); i++)
        cout << columns[i] << " ";*/
}

