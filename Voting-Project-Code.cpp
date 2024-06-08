/* Library Files */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <string>
#include <limits>
using namespace std;
/* Library Files */
/* Structure Named office Defined to create datatype for *officers information */
struct office
{
    string Name, Email, Password, CNIC, Emp_Id;
};
/* Structure Named office Defined to create datatype for *officers information */
struct voters
{
    string Name, CNIC, Sil_No, H_No, Li_No;
};
struct Candits_St
{
    string Name, Party, Sym_alloted;
};
office Officer_input;
voters voter_input;
const int max_na_cadtis = 20, max_pp_cadtis = 17;
int Votes_calculation[max_na_cadtis];
int Votes_calculation1[max_pp_cadtis];
class Office
{
public:
    int officers_data_fetching(office Officers[])
    {
        ifstream File, File_again;
        ofstream File_copy;
        string St_Check_Officers;
        int file_pres, no_officers;
        File.open("Officers File.txt");
        if (File.is_open())
        {
            int lines{0};
            File_copy.open("Officers Copy.txt");
            while (getline(File, St_Check_Officers))
            {
                File_copy << St_Check_Officers << endl;
                lines++;
            }
            File_copy.close();
            File.close();
            no_officers = lines / 5;
            if (no_officers > 0 && no_officers <= 10)
            {
                File_again.open("Officers Copy.txt");
                for (int i{0}; i < no_officers; i++)
                {
                    getline(File_again, Officers[i].CNIC);
                    getline(File_again, Officers[i].Emp_Id);
                    getline(File_again, Officers[i].Name);
                    getline(File_again, Officers[i].Email);
                    getline(File_again, Officers[i].Password);
                }
                File_again.close();
                remove("Officers Copy.txt");
                file_pres = 1;
            }
        }
        else
        {
            file_pres = 0;
        }
        if (file_pres == 1)
        {
            return no_officers;
        }
        else
        {
            no_officers = 0;
            return no_officers;
        }
    }
    int Officers_Validation()
    {
        int count = 0, Length_o_cnic, Length_o_eid, Length_o_name, Length_o_email, Length_o_pass, data_validation = 0;
        bool cdts[5] = {0, 0, 0, 0, 0};
        while (!cdts[0])
        {
            if (count > 0)
            {
                cout << "\n\t\aPlease Enter Your Correct CNIC : ";
            }
            else
            {
                cout << "\n\tEnter Your CNIC : ";
            }
            getline(cin, Officer_input.CNIC);
            Length_o_cnic = Officer_input.CNIC.length();
            if (Length_o_cnic == 13)
            {
                int No_alphab_s = 0;
                for (int i{0}; i < 13; i++)
                {
                    if (!isalpha(Officer_input.CNIC[i]) && !isspace(Officer_input.CNIC[i]))
                    {
                        No_alphab_s++;
                    }
                }
                if (No_alphab_s == 13)
                {
                    cdts[0] = 1;
                    count = 0;
                }
            }
            else
            {
                cdts[0] = 0;
                count++;
            }
        }
        while (!cdts[1])
        {
            if (count > 0)
            {
                cout << "\n\t\aPlease Enter Your Correct Employee Id : ";
            }
            else
            {
                cout << "\n\tEnter Your Employee Id : ";
            }
            getline(cin, Officer_input.Emp_Id);
            Length_o_eid = Officer_input.Emp_Id.length();
            if (Length_o_eid == 3)
            {
                int No_alphab_s = 0;
                for (int i{0}; i < 3; i++)
                {
                    if (!isalpha(Officer_input.Emp_Id[i]) && !isspace(Officer_input.Emp_Id[i]))
                    {
                        No_alphab_s++;
                    }
                }
                if (No_alphab_s == 3)
                {
                    cdts[1] = 1;
                    count = 0;
                }
            }
            else
            {
                cdts[1] = 0;
                count++;
            }
        }
        while (!cdts[2])
        {
            if (count > 0)
            {
                cout << "\n\t\aPlease Enter Your Correct Full Name : ";
            }
            else
            {
                cout << "\n\tEnter Your Full Name : ";
            }
            getline(cin, Officer_input.Name);
            Length_o_name = Officer_input.Name.length();
            int alphab = 0, space = 0;
            for (int i{0}; i < Length_o_name; i++)
            {
                if (isalpha(Officer_input.Name[i]))
                {
                    alphab++;
                }
                if (isspace(Officer_input.Name[i]))
                {
                    space++;
                }
            }
            if (space > 0 && alphab + space == Length_o_name)
            {
                cdts[2] = 1;
                count = 0;
            }
            else
            {
                cdts[2] = 0;
                count++;
            }
        }
        while (!cdts[3])
        {
            if (count > 0)
            {
                cout << "\n\t\aPlease Enter Your Correct Email : ";
            }
            else
            {
                cout << "\n\tEnter Your Email : ";
            }
            getline(cin, Officer_input.Email);
            Length_o_email = Officer_input.Email.length();
            int alphab = 0, digit = 0, at = 0, dot = 0;
            for (int i{0}; i < Length_o_email; i++)
            {
                if (isalpha(Officer_input.Email[i]))
                {
                    alphab++;
                }
                if (isdigit(Officer_input.Email[i]))
                {
                    digit++;
                }
                if (Officer_input.Email[i] == '@')
                {
                    at = 1;
                }
                if (Officer_input.Email[i] == '.')
                {
                    dot = 1;
                }
            }
            if (digit > 0 && alphab > 0 && at == 1 && dot == 1 && (alphab + digit + at + dot) == Length_o_email)
            {
                cdts[3] = 1;
                count = 0;
            }
            else
            {
                cdts[3] = 0;
                count++;
            }
        }
        while (!cdts[4])
        {
            if (count > 0)
            {
                cout << "\n\t\aPlease Enter Your Correct Password\n\n\t(Must Have 1 Uppercase and 1 Lowercase Alphabet \n\n\t and digits and Length Must be >= 6 and <= 10) : ";
            }
            else
            {
                cout << "\n\tEnter Your Password : ";
            }
            getline(cin, Officer_input.Password);
            Length_o_pass = Officer_input.Password.length();
            int alphab_u = 0, alphab_l = 0, digit = 0;
            for (int i{0}; i < Length_o_pass; i++)
            {
                if (isupper(Officer_input.Password[i]))
                {
                    alphab_u++;
                }
                if (islower(Officer_input.Password[i]))
                {
                    alphab_l++;
                }
                if (isdigit(Officer_input.Password[i]))
                {
                    digit++;
                }
            }
            if (digit > 0 && alphab_u > 0 && alphab_l > 0 && (alphab_u + alphab_l + digit) == Length_o_pass && Length_o_pass >= 6 && Length_o_pass <= 10)
            {
                cdts[4] = 1;
                count = 0;
            }
            else
            {
                cdts[4] = 0;
                count++;
            }
        }
        for (int i{0}; i < 5; i++)
        {
            if (cdts[i])
            {
                data_validation++;
            }
        }
        if (data_validation == 5)
        {
            return data_validation;
        }
        else
        {
            return 0;
        }
    }
    int Compare_Officers_data(int no_officers, office Officers[])
    {
        int values_corec = 0;
        for (int i = 0; i < no_officers; i++)
        {
            if ((Officers[i].CNIC == Officer_input.CNIC))
            {
                values_corec = i;
                break;
            }
            else
            {
                values_corec = -1;
            }
        }
        if (values_corec != -1)
        {
            if ((Officer_input.Emp_Id == Officers[values_corec].Emp_Id) && (Officer_input.Name == Officers[values_corec].Name) && (Officer_input.Email == Officers[values_corec].Email) && (Officer_input.Password == Officers[values_corec].Password))
            {
                values_corec = 5;
            }
            else
            {
                values_corec = -1;
            }
        }
        else
        {
            values_corec = -1;
        }
        return values_corec;
    }
};
class Voters
{
public:
    int fetch_voters_data(voters Voters[])
    {
        ifstream File, File_again;
        ofstream File_copy;
        string St_Check_Officers;
        int file_pres, no_voters;
        File.open("Voter List 2024.txt");
        if (File.is_open())
        {
            int lines{0};
            File_copy.open("Voter List 2024 Copy.txt");
            while (getline(File, St_Check_Officers))
            {
                File_copy << St_Check_Officers << endl;
                lines++;
            }
            File_copy.close();
            File.close();
            no_voters = lines / 5;
            if (no_voters > 0 && no_voters <= 500)
            {
                File_again.open("Voter List 2024 Copy.txt");
                for (int i{0}; i < no_voters; i++)
                {
                    getline(File_again, Voters[i].Name);
                    getline(File_again, Voters[i].CNIC);
                    getline(File_again, Voters[i].Sil_No);
                    getline(File_again, Voters[i].H_No);
                    getline(File_again, Voters[i].Li_No);
                }
                File_again.close();
                remove("Voter List 2024 Copy.txt");
                file_pres = 1;
            }
            else
            {
                file_pres = 0;
            }
        }
        else
        {
            file_pres = 0;
        }
        if (file_pres == 1)
        {
            return no_voters;
        }
        else
        {
            no_voters = 0;
            return no_voters;
        }
    }
    int voters_verification(int no_o_voters, voters Voters[])
    {
        int count = 0, Length_o_cnic, corect = 0;
        bool cdts{0};
        while (!cdts)
        {
            if (count > 0)
            {
                cout << "\n\t\aPlease Enter Correct CNIC : ";
            }
            else
            {
                cout << "\n\tEnter Voters CNIC Here : ";
            }
            cin.ignore();
            getline(cin, voter_input.CNIC);
            Length_o_cnic = voter_input.CNIC.length();
            if (Length_o_cnic == 13)
            {
                int No_alphab_s = 0;
                for (int i{0}; i < 13; i++)
                {
                    if (!isalpha(voter_input.CNIC[i]) && !isspace(voter_input.CNIC[i]))
                    {
                        No_alphab_s++;
                    }
                }
                if (No_alphab_s == 13)
                {
                    cdts = 1;
                    count = 0;
                }
            }
            else
            {
                cdts = 0;
                count++;
            }
        }
        for (int i = 0; i < no_o_voters; i++)
        {
            if ((voter_input.CNIC == Voters[i].CNIC))
            {
                corect = i;
                break;
            }
            else
            {
                corect = -1;
            }
        }
        if (corect != -1)
        {
            cout << "\n\n\tVoter Exist With That CNIC And Its Information is Given Below : \n\n\t";
            cout << "Name : " << Voters[corect].Name;
            cout << "\n\n\tCNIC : " << Voters[corect].CNIC;
            cout << "\n\n\tSilsila No : " << Voters[corect].Sil_No;
            cout << "\n\n\tHome No : " << Voters[corect].H_No;
            cout << "\n\n\tVoter List No : " << Voters[corect].Li_No;
            return corect;
        }
        else
        {
            corect = -1;
            return corect;
        }
    }
    int polled_voters(int no_o_voters, int voter_no, string Polled_Voters[])
    {
        ifstream File, File_again;
        ofstream File_copy;
        string St_check_line;
        int lines = 0, casted = 0;
        File.open("Polled Voters.txt");
        File_copy.open("Polled Voters Copy.txt");
        while (getline(File, St_check_line))
        {
            File_copy << St_check_line << endl;
            lines++;
        }
        File_copy.close();
        File.close();
        if (lines > 0 && lines <= no_o_voters)
        {
            File_again.open("Polled Voters Copy.txt");
            for (int i = 0; i < lines; i++)
            {
                getline(File_again, Polled_Voters[i]);
            }
            File_again.close();
            remove("Polled Voters Copy.txt");
            for (int i = 0; i < lines; i++)
            {
                if ((voter_input.CNIC == Polled_Voters[i]))
                {
                    casted = 1;
                    break;
                }
                else
                {
                    casted = 0;
                }
            }
        }
        if (lines == no_o_voters)
        {
            casted = lines;
        }
        else if (lines > no_o_voters)
        {
            casted = -1;
        }
        return casted;
    }
};
int na50_cadts_data_fetching(Candits_St NA_50[])
{
    ifstream File, File_again;
    ofstream File_copy;
    string St_Check_cadts;
    int file_pres, no_Na_50cadts;
    File.open("NA-50 Candidates 2024.txt");
    if (File.is_open())
    {
        int lines{0};
        File_copy.open("NA-50 Candidates 2024 Copy.txt");
        while (getline(File, St_Check_cadts))
        {
            File_copy << St_Check_cadts << endl;
            lines++;
        }
        File_copy.close();
        File.close();
        no_Na_50cadts = lines / 3;
        if (no_Na_50cadts > 0 && no_Na_50cadts <= 20)
        {
            File_again.open("NA-50 Candidates 2024 Copy.txt");
            for (int i{0}; i < no_Na_50cadts; i++)
            {
                getline(File_again, NA_50[i].Name);
                getline(File_again, NA_50[i].Party);
                getline(File_again, NA_50[i].Sym_alloted);
            }
            File_again.close();
            remove("NA-50 Candidates 2024 Copy.txt");
            file_pres = 1;
        }
        else
        {
            file_pres = 0;
        }
    }
    else
    {
        file_pres = 0;
    }
    if (file_pres == 1)
    {
        return no_Na_50cadts;
    }
    else
    {
        no_Na_50cadts = 0;
        return no_Na_50cadts;
    }
}
int pp4_cadts_data_fetching(Candits_St PP_4[])
{
    ifstream File, File_again;
    ofstream File_copy;
    string St_Check_cadts;
    int file_pres, no_pp_4cadts;
    File.open("PP-4 Candidates 2024.txt");
    if (File.is_open())
    {
        int lines{0};
        File_copy.open("PP-4 Candidates 2024 Copy.txt");
        while (getline(File, St_Check_cadts))
        {
            File_copy << St_Check_cadts << endl;
            lines++;
        }
        File_copy.close();
        File.close();
        no_pp_4cadts = lines / 3;
        if (no_pp_4cadts > 0 && no_pp_4cadts <= 17)
        {
            File_again.open("PP-4 Candidates 2024 Copy.txt");
            for (int i{0}; i < no_pp_4cadts; i++)
            {
                getline(File_again, PP_4[i].Name);
                getline(File_again, PP_4[i].Party);
                getline(File_again, PP_4[i].Sym_alloted);
            }
            File_again.close();
            remove("PP-4 Candidates 2024 Copy.txt");
            file_pres = 1;
        }
        else
        {
            file_pres = 0;
        }
    }
    else
    {
        file_pres = 0;
    }
    if (file_pres == 1)
    {
        return no_pp_4cadts;
    }
    else
    {
        no_pp_4cadts = 0;
        return no_pp_4cadts;
    }
}
int polling_process(int voter_no, voters Voters[], Candits_St NA_50[], Candits_St PP_4[], int no_of_na_candits, int no_of_pp_candits, int Votes_calculation[], int Votes_calculation1[])
{
    ofstream File, File1_NA, File1_PP;
    int action, action1;
    File.open("Polled Voters.txt", ios::app);
    File << Voters[voter_no].CNIC << endl;
    File.close();
    cout << "\n\n\n\tDear " << Voters[voter_no].Name << " Please Vote For Your Right\n\tSelect NA-50 Candidate First From The List That You Want To Vote : \n\n\t\t\t\tNA-50 Candidates\n\n";
    for (int i = 0; i < no_of_na_candits; i++)
    {
        cout << "____________________________________________________________________________\n\n";
        cout << "| " << i + 1 << " | " << NA_50[i].Name << " | " << NA_50[i].Party << " | " << NA_50[i].Sym_alloted << " |\n";
        cout << "____________________________________";
    }
    cout << "\n\n\tNow Enter Your Choice Here : ";
    while (!(cin >> action) || action < 1 || action > no_of_na_candits)
    {
        cout << "\n\n\tInvalid input.\n\n\tEnter Choice Again (Between 1 TO " << no_of_na_candits << " ) : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (action)
    {
    case 1:
        Votes_calculation[action - 1]++;
        break;
    case 2:
        Votes_calculation[action - 1]++;
        break;
    case 3:
        Votes_calculation[action - 1]++;
        break;
    case 4:
        Votes_calculation[action - 1]++;
        break;
    case 5:
        Votes_calculation[action - 1]++;
        break;
    case 6:
        Votes_calculation[action - 1]++;
        break;
    case 7:
        Votes_calculation[action - 1]++;
        break;
    case 8:
        Votes_calculation[action - 1]++;
        break;
    case 9:
        Votes_calculation[action - 1]++;
        break;
    case 10:
        Votes_calculation[action - 1]++;
        break;
    case 11:
        Votes_calculation[action - 1]++;
        break;
    case 12:
        Votes_calculation[action - 1]++;
        break;
    case 13:
        Votes_calculation[action - 1]++;
        break;
    case 14:
        Votes_calculation[action - 1]++;
        break;
    case 15:
        Votes_calculation[action - 1]++;
        break;
    case 16:
        Votes_calculation[action - 1]++;
        break;
    case 17:
        Votes_calculation[action - 1]++;
        break;
    case 18:
        Votes_calculation[action - 1]++;
        break;
    case 19:
        Votes_calculation[action - 1]++;
        break;
    case 20:
        Votes_calculation[action - 1]++;
        break;
    default:
        cout << "\n\n\tInvalid Candidate Selected";
        break;
    }
    cout << "\n\n\n\tDear " << Voters[voter_no].Name << " Please Vote For Your Right\n\tSelect PP-4 Candidate First From The List That You Want To Vote : \n\n\t\t\t\tPP-4 Candidates\n\n";
    for (int i = 0; i < no_of_pp_candits; i++)
    {
        cout << "____________________________________________________________________________\n\n";
        cout << "| " << i + 1 << " | " << PP_4[i].Name << " | " << PP_4[i].Party << " | " << PP_4[i].Sym_alloted << " |\n";
        cout << "____________________________________";
    }
    cout << "\n\n\tNow Enter Your Choice Here : ";
    while (!(cin >> action1) || action1 < 1 || action1 > no_of_pp_candits)
    {
        cout << "\n\n\tInvalid input.\n\n\tEnter Choice Again (Between 1 TO " << no_of_pp_candits << " ) : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (action1)
    {
    case 1:
        Votes_calculation1[action1 - 1]++;
        break;
    case 2:
        Votes_calculation1[action1 - 1]++;
        break;
    case 3:
        Votes_calculation1[action1 - 1]++;
        break;
    case 4:
        Votes_calculation1[action1 - 1]++;
        break;
    case 5:
        Votes_calculation1[action1 - 1]++;
        break;
    case 6:
        Votes_calculation1[action1 - 1]++;
        break;
    case 7:
        Votes_calculation1[action1 - 1]++;
        break;
    case 8:
        Votes_calculation1[action1 - 1]++;
        break;
    case 9:
        Votes_calculation1[action1 - 1]++;
        break;
    case 10:
        Votes_calculation1[action1 - 1]++;
        break;
    case 11:
        Votes_calculation1[action1 - 1]++;
        break;
    case 12:
        Votes_calculation1[action1 - 1]++;
        break;
    case 13:
        Votes_calculation1[action1 - 1]++;
        break;
    case 14:
        Votes_calculation1[action1 - 1]++;
        break;
    case 15:
        Votes_calculation1[action1 - 1]++;
        break;
    case 16:
        Votes_calculation1[action1 - 1]++;
        break;
    case 17:
        Votes_calculation1[action1 - 1]++;
        break;
    case 18:
        Votes_calculation1[action1 - 1]++;
        break;
    case 19:
        Votes_calculation1[action1 - 1]++;
        break;
    case 20:
        Votes_calculation1[action1 - 1]++;
        break;
    default:
        cout << "\n\n\tInvalid Candidate Selected";
        break;
    }
    cout << "\n\n\n\tDear " << Voters[voter_no].Name << "! Thanks For Voting";
    remove("NA Result.txt");
    File1_NA.open("NA Result.txt");
    for (int i{0}; i < no_of_na_candits; i++)
    {
        File1_NA << Votes_calculation[i] << endl;
    }
    File1_NA.close();
    remove("PP Result.txt");
    File1_PP.open("PP Result.txt");
    for (int i{0}; i < no_of_pp_candits; i++)
    {
        File1_PP << Votes_calculation1[i] << endl;
    }
    File1_PP.close();
}
int Result_Getting(int Votes_calculation[], int Votes_calculation1[], int no_o_na_candits, int no_o_pp_candits, Candits_St NA_50[], Candits_St PP_4[])
{
    ifstream File1NA, File1PP;
    File1NA.open("NA Result.txt");
    for (int i{0}; i < no_o_na_candits; i++)
    {
        File1NA >> Votes_calculation[i];
    }
    File1NA.close();
    File1PP.open("PP Result.txt");
    for (int i{0}; i < no_o_pp_candits; i++)
    {
        File1PP >> Votes_calculation1[i];
    }
    File1PP.close();
}
int Result_display(int no_o_na_candits, Candits_St NA_50[], int no_o_pp_candits, Candits_St PP_4[], int no_o_voters)
{
    system("cls");
    cout << "\n\n\n\n\tResult Copy is Generted So Wxit The Program To Check The Result\n";
    int temp;
    string temp_st;
    ofstream File;
    File.open("Result Form For NA-50 and PP-4.html");
    File << "<!DOCTYPE html>\n<html>\n<head>\n<style>\ntable td{\npadding:10px;\ntext-align: center;}\n</style>\n\n<title>\nResult Form For NA-50 and PP-4\n</title>\n<head>\n</head>\n<body bgcolor='skyblue'>\n<h1>\nGeneral Elections Pakistan 2024\n</h1>\n<h2>\nResults For NA-50 Seat\n</h2>\n<ul>\n<li>\nTotal Voters Registered : " << no_o_voters << "\n</li>\n<li>\nTotal Candidates : " << no_o_na_candits << "\n</li>\n</ul>\n<table border='1px'>\n<thead>\n<th>\nNo.\n</th>\n<th>\nName\n</th>\n<th>\nParty\n</th>\n<th>\nSymboll\n</th>\n<th>\nVotes Taken\n</th>\n</thead>\n";
    for (int i{0}; i < no_o_na_candits; i++)
    {
        File << "<tr>\n<td>\n"
             << i + 1 << "\n</td>\n<td>\n"
             << NA_50[i].Name << "\n</td>\n<td>\n"
             << NA_50[i].Party << "\n</td>\n<td>\n"
             << NA_50[i].Sym_alloted << "\n</td>\n<td>\n"
             << Votes_calculation[i] << "\n</td>\n</tr>\n";
    }
    File << "</table>\n<h2>\nResult For PP-4 Seat\n</h2>\n<ul>\n<li>\nTotal Candidates : " << no_o_pp_candits << "\n</li>\n</ul>\n<table border='1px'>\n<thead>\n<th>\nNo.\n</th>\n<th>\nName\n</th>\n<th>\nParty\n</th>\n<th>\nSymboll\n</th>\n<th>\nVotes Taken\n</th>\n</head>";
    for (int i{0}; i < no_o_pp_candits; i++)
    {
        File << "<tr>\n<td>\n"
             << i + 1 << "\n</td>\n<td>\n"
             << PP_4[i].Name << "\n</td>\n<td>\n"
             << PP_4[i].Party << "\n</td>\n<td>\n"
             << PP_4[i].Sym_alloted << "\n</td>\n<td>\n"
             << Votes_calculation1[i] << "\n</td>\n</tr>\n";
    }
    File << "</table>\n</body>\n</html>";
    File.close();
}
int main()
{
    Office Obj1;
    Voters Obje1;
    ofstream File_write, File_write1;
    ifstream File_read, File_read1;
    const int max_officers = 10, max_voters = 500;
    office Officers[max_officers];
    voters Voters[max_voters];
    Candits_St NA_50[max_na_cadtis];
    Candits_St PP_4[max_pp_cadtis];
    string Polled_Voters[max_voters];
    cout << "\n\n\t\tWelcome To 2024 Voting Program For Gulial Khauran , Union Council Khaur , Tehsil Pindi Gheb , District Attock , Punjab , Pakistan\n\n\t\t\t\tDear Officer Enter Your Complete and Correct Infomation for Security To Start Voting\n\n";
    int no_o_officers = Obj1.officers_data_fetching(Officers);
    int no_o_voters = Obje1.fetch_voters_data(Voters);
    int no_o_na_candits = na50_cadts_data_fetching(NA_50);
    int no_o_pp_candits = pp4_cadts_data_fetching(PP_4);
    int voter_verification;
    int polled_voter_verifiction;
    File_read.open("NA Result.txt");
    if (File_read.is_open())
    {
        Votes_calculation[no_o_na_candits];
        for (int i = 0; i < no_o_na_candits; i++)
        {
            File_read >> Votes_calculation[i];
        }
    }
    else
    {
        for (int i = 0; i < no_o_na_candits; i++)
        {
            Votes_calculation[i] = 0;
        }
        File_write.open("NA Result.txt");
        for (int i = 0; i < no_o_na_candits; i++)
        {
            File_write << Votes_calculation[i] << endl;
        }
    }
    File_read1.open("PP Result.txt");
    if (File_read1.is_open())
    {
        Votes_calculation1[no_o_pp_candits];
        for (int i = 0; i < no_o_pp_candits; i++)
        {
            File_read1 >> Votes_calculation1[i];
        }
    }
    else
    {
        for (int i = 0; i < no_o_pp_candits; i++)
        {
            Votes_calculation1[i] = 0;
        }
        File_write1.open("PP Result.txt");
        for (int i = 0; i < no_o_pp_candits; i++)
        {
            File_write1 << Votes_calculation1[i] << endl;
        }
    }
    int comparision, count_action = 0;
    bool cdts_action = 0;
    if (no_o_officers == 0)
    {
        cout << "\n\n\t\t\t\a(Officers File.txt) is Not Available\n\n\n \t\t\t\t\tOR \n\n\n\t\t\tDoes't Have Officers > 0 And <= 10 \n\n\n\t\t\tPlease Provide (Officers File.txt)\n\n\n"
             << endl
             << endl;
        ofstream File;
        File.open("Officers Copy.txt");
        File.close();
        remove("Officers Copy.txt");
    }
    else
    {
        int data_validation = Obj1.Officers_Validation();
        if (data_validation == 5)
        {
            comparision = Obj1.Compare_Officers_data(no_o_officers, Officers);
            if (comparision == 5)
            {
                cout << "\n\n\tOfficer Information Verified Successfully"
                     << endl;
                int action;
                while (action != 2)
                {
                    cout << "\n\n\tSelect Your Choice From Below\n\n\t(When Polling Process Completes Then Program Displays The Result)\n\n\t1.Poll A Vote\n\n\t2.Exit Program\n\n\tEnter Your Choice : ";
                    while (!(cin >> action) || action < 1 || action > 2)
                    {
                        cout << "\n\n\tInvalid input.\n\n\tEnter Choice Again : ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (action)
                    {
                    case 1:
                        if (no_o_voters == 0)
                        {
                            cout << "\n\n\t\t\t\a(Voter List 2024.txt) is Not Available\n\n\n \t\t\t\t\tOR \n\n\n\t\t\tDoes't Have Voters > 0 And <= 500 \n\n\n\t\t\tPlease Provide (Voter List 2024.txt)\n\n\n"
                                 << endl
                                 << endl;
                        }
                        else
                        {
                            cout << "\n\n\t" << no_o_voters << " Voters Are Present in The List" << endl;
                            voter_verification = Obje1.voters_verification(no_o_voters, Voters);
                            if (voter_verification == -1)
                            {
                                cout << "\n\tVoter With That CNIC is Not Registered";
                            }
                            else
                            {
                                polled_voter_verifiction = Obje1.polled_voters(no_o_voters, voter_verification, Polled_Voters);
                                if (polled_voter_verifiction == no_o_voters)
                                {
                                    cout << "\n\n\tVoter With That CNIC Has Already Casted The Vote";
                                    Result_display(no_o_na_candits, NA_50, no_o_pp_candits, PP_4, no_o_voters);
                                    return 0;
                                }
                                else if (polled_voter_verifiction == 1)
                                {
                                    cout << "\n\n\tVoter With That CNIC Has Already Casted The Vote";
                                }
                                else if (polled_voter_verifiction == 0)
                                {
                                    if ((no_o_na_candits == 0 || no_o_pp_candits == 0) || ((no_o_na_candits > max_na_cadtis) || (no_o_pp_candits > max_pp_cadtis)))
                                    {
                                        cout << "\n\n\n\t(NA-50 Candidates 2024.txt) and (PP-4 Candidates 2024.txt) Please Provide These Files\n\n\n\t\t\t\tOR\n\n\n\tNo of PP-4 Candidates Are > 17 OR No of NA-50 Candidates Are > 20 Which is Not Allowed";
                                    }
                                    else
                                    {
                                        polling_process(voter_verification, Voters, NA_50, PP_4, no_o_na_candits, no_o_pp_candits, Votes_calculation, Votes_calculation1);
                                        Result_Getting(Votes_calculation, Votes_calculation1, no_o_na_candits, no_o_pp_candits, NA_50, PP_4);
                                    }
                                }
                                else
                                {
                                    cout << "\n\n\tWrong File";
                                }
                            }
                        }
                        break;
                    case 2:
                        cout << "\n\n\tExisting The Voting Program\n\n\n"
                             << endl;
                        break;
                    default:
                        cout << "\n\n\tAction is Invalid" << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "\n\n\t\aWrong Information Of Officer\n"
                     << endl
                     << endl;
            }
        }
    }
    return 0;
}