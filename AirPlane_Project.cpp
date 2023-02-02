//Amirreza Paydar
//پروژه نهایی فرودگاه
#include <iostream>
#include <string.h>
using namespace std;
struct FLIGHT
{
    char id[11];
    char origin[50];
    char destination[50];
    int date_year;
    int date_day;
    int date_month;
    int date_hour;
    int date_minute;
    char airline[25];
    int capacity;
    int capacity_remains;
    int n_b_tick = 0;
    char name[25];
    char name_kh[25];
    char user_user[10];
};
struct ADMIN
{
    char user[10];
    char pass[25];
    char verf_pass[25];
    char name[25];
    char name_kh[25];
    char phone[11];
};
struct USER
{
    char user[10];
    char pass[25];
    char verf_pass[25];
    char name[25];
    char name_kh[25];
    char phone[11];    
};

//این متغیر ها تعداد های مختلف را میشمارند
int n_reg_usr = 0, n_reg_adm = 0, n_flgh_adm = 0, num_usr;

ADMIN admin[11];

USER user[11];

FLIGHT flight[11];

FLIGHT flight_user[11][5];

//این تابع بین توابع مختلف حرکت میکند
void switch_between_functions(int code);

//این تابع پرواز های جدید را ثبت میکند
int add_flight();

//منو اصلی برای انتقال بین پنل های ادمین و یوز و خروج
int main_menu();

//پنل ادمین
int admin_panel();

//پنل لاگین ادمین
int login_admin_panel();

//قسمت ثبت نام برای ادمین
int signup_admin_panel();

//پنلی برای هر قسمتی از ثبت نام که ارور داد که از کاربر بخواهد که ادامه دهد یا به پنل ادمین برگردد
int error_menu_admin();

//داشبورد ادمین
int admin_dashbord();

//این تابع مربوط به آمارگیری پرواز پنل ادمین هست
int flight_trc_stat();

//تاییدیه پرواز مخصوص پنل ادمین
int tick_conf();

//مشاهده تمام پرواز ها برای ادمین
int flight_monitoring_adm();

//پنل یوزر
int user_panel();

//پنل لاگین یوزر
int login_user_panel();

//قسمت ثبت نام برای یوزر
int signup_user_panel();

//پنلی برای هر قسمتی از ثبت نام که ارور داد که از کاربر بخواهد که ادامه دهد یا به پنل یوزر برگردد
int error_menu_user();

//داشبورد ادمین
int user_dashbord();

//خرید بلیط کاربر
int buy_ticket();

//مشاهده تمام پرواز ها برای کاربر
int flight_monitoring();

//مشاهده بلیط های خریداری شده توسط کاربر
int view_purchased_tickets();

//تمام کار های انجام شده داخل ادمین
void admin_log();

//تمام کار های انجام شده داخل یوزر
void user_log();

int main()
{
    while(1)
    {
        int code;
        code = main_menu();
        if(code==3)
            break;
        switch_between_functions(code);
    }
    return 0;
}
void admin_log()
{
    while(1)
    {
        int x = admin_panel();
        if(x==1)
        {    
            int z = login_admin_panel();
            if(z==1)
            {
                while(1)
                {
                    int r = admin_dashbord();
                    if(r==1)
                    {    
                        int y = add_flight();
                    }
                    if(r==2)
                    {
                        int y = flight_trc_stat();
                    }
                    if(r==3)
                    {
                        int y = tick_conf();
                    }
                    if(r==4)
                    {
                        int y = flight_monitoring_adm();    
                    }
                    if(r==5)
                    {
                        break;
                    }
                } 
            }
        }    
            if(x==2)
            {    
                while(1)
                {
                    int y = signup_admin_panel();
                    break;
                }                  
            }              
            if(x==3)       
                break;    
    } 
}
void user_log()
{
    while(1)
    {
        int x = user_panel();
        if(x==1)
        {    
            int z = login_user_panel();
            if(z==1)
            {
                while(1)
                {
                    int r = user_dashbord();
                    if(r==1)
                    {
                        int y = buy_ticket();                                
                    }
                    if(r==2)
                    {
                        int y = flight_monitoring();
                    }
                    if(r==3)
                    {
                        int y = view_purchased_tickets();
                    }
                    if(r==4)
                    {
                        break;
                    }
                }
            }
        }    
        if(x==2)
        {    
            while(1)
            {
                int y = signup_user_panel();    
                break;
            }
        }                                
        if(x==3)       
            break;     
    }        
}

void switch_between_functions(int code)
{
    while(1)
    {
        switch (code)
        {
            case 1 :
                while(1)
                {
                    admin_log();
                    break;
                }
                break;                           
            case 2 :
                while(1)
                {
                    user_log();
                    break;            
                }
                break;            
            default:
                cout<<"Invalid Numbar|TryAgain!"<<endl;
                break;
        }
        break;
    }
}
int main_menu()
{
    int x;
    cout<<"\t!!!WELCOME!!!"<<endl<<"1-Go To Admin Panel"<<endl<<"2-Go To User Panel"<<endl<<"3-Exit"<<endl;
    cout<<"Lotfan Adad mored nazar ra vared koned:"<<endl;
    cin>>x;          
    return x;
}
int admin_panel()
{
    while(1)
    {
        int code;
        cout<<"\t.::ADMIN PANEL::."<<endl;
        cout<<"1-Login"<<endl<<"2-Signup"<<endl<<"3-Go Back"<<endl;
        cout<<"Lotfan Adad mored nazar ra vared koned:"<<endl;
        cin>>code;
        switch (code)
        {
            case 1 :
                return 1;
                break;
            case 2 :
                return 2;
                break;
            case 3 :
                return 3;
                break;    
            default:
                cout<<"Invalid Numbar|TryAgain!"<<endl;
                continue;
        }
    }    

}
int login_admin_panel()
{
    int x = 0;
    cout<<"\t.::ADMIN LOGIN PANEL::."<<endl;
    cout<<"Enter your username"<<endl;
    cin>>admin[10].user;
    cout<<"Enter your password"<<endl;
    cin>>admin[10].pass;
    for(int i=0; i<10; i++)
    {
        if(strcmp(admin[10].user, admin[i].user)==0 && strcmp(admin[10].pass, admin[i].pass)==0)
        {    
            x = 1;
            break;
        }    
    }
    if(x == 0)
    {
        cout<<"Invalid information!"<<endl;
        cout<<"Getting back to Admin panel..."<<endl;
        return 0;
    }
    else
        return 1;
}
int signup_admin_panel()
{
    if(n_reg_adm==10)
    {    
        cout<<"Admins Are Full!(max admins = 10)"<<endl;
        return n_reg_adm;//عجبXD
    }    
    else
    {
        cout<<"\t.::ADMIN SIGNUP MENU::."<<endl;
        while(1)
        {
            cout<<"Enter your name"<<endl;
            cin>>admin[n_reg_adm].name;
            if(strlen(admin[n_reg_adm].name)>25)
            {
                cout<<"Name is too long(max=25 character)"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }    
            else
                break;    
        }            
        while(1)
        {
            cout<<"Enter your family"<<endl;
            cin>>admin[n_reg_adm].name_kh;
            if(strlen(admin[n_reg_adm].name_kh)>25)
            {    
                cout<<"Family is too long(max=25 character)"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            else
                break;    
        }        
        while(1)
        {
            int x = 1;
            cout<<"Enter your phone number"<<endl;
            cin>>admin[n_reg_adm].phone;
            if(admin[n_reg_adm].phone[0] != '0')
            {    
                cout<<"Phone number must start with zero"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }    
            if(strlen(admin[n_reg_adm].phone) != 11)
            {
                cout<<"Phone number must have 11 digits"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;          
            } 
            for(int i=0; i<11; i++)
            {
                if(admin[n_reg_adm].phone[i] >= '0' && admin[n_reg_adm].phone[i] <= '9');
                else
                {
                    cout<<"Phone number digits must be between 0 and 9"<<endl;
                    x = 0;
                    break;
                }
            }
            if(x==1)
                break;
            if(x==0)
            {    
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }        
        }
        while(1)
        {    
            int n = 0;
            cout<<"Enter your username"<<endl;
            cin>>admin[n_reg_adm].user;
            if(strlen(admin[n_reg_adm].user) < 2 || strlen(admin[n_reg_adm].user) > 10)
            {    
                cout<<"username is too long or too short(max character=10 and min character=2)"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            for(int i=0; i<10; i++)
            {
                if(strcmp(admin[n_reg_adm].user, admin[i].user)==0)
                    ++n;    
            }
            //شرط پایین به دلیل این بزرگتر از 1 هست چون در بین بازه 10 تایی حلقه بالا یکبار خود یوزنیم هم دوباره تکرار میشود پس باید بیشتر از یکبار یوزرنیم تکراری باشد
            if(n>1)
            {
                cout<<"The username is duplicate"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            else 
                break;   
        }        
        while(1)
        {
            int n1=0, n2=0, n3=0;
            cout<<"Enter your password"<<endl;
            cin>>admin[n_reg_adm].pass;
            int q = strlen(admin[n_reg_adm].pass);
            if(q < 5 || q > 25)
            {
                cout<<"Password is too long or too short(max character=25 and min character=5)"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            for(int i=0; i<=q; i++)
            {
                if(admin[n_reg_adm].pass[i] >= '0' && admin[n_reg_adm].pass[i] <= '9')
                    n1++;
                if(admin[n_reg_adm].pass[i] >= 'a' && admin[n_reg_adm].pass[i] <= 'z')
                    n2++;
                if(admin[n_reg_adm].pass[i] >= 'A' && admin[n_reg_adm].pass[i] <= 'Z')
                    n3++;        
            }
            //اگر هر کدام از شرط ها برقرار نباشد یکی از متغر ها صفر میباشد و  شرط پایین برقرار میشود
            if(n1<1 || n2<1 || n3<1)
            {
                cout<<"The password must have at least one digit, one lowercase and one uppercase letter"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            break;
        }
        while(1)
        {   
            cout<<"Enter your password again"<<endl;
            cin>>admin[n_reg_adm].verf_pass;
            if(strcmp(admin[n_reg_adm].verf_pass, admin[n_reg_adm].pass)!=0)
            {
                cout<<"Password confirmation is incorrect"<<endl;
                int g = error_menu_admin();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            break;
        }    
        n_reg_adm = n_reg_adm + 1;
        cout<<"sign up is successful!"<<endl;
        return n_reg_adm;    
    }        
}
int error_menu_admin()
{
    int x;
    cout<<"1-Return to your own panel"<<endl<<"2-Try Again"<<endl;
    cin>>x;
    return x;
}
int admin_dashbord()
{
    int x;
    cout<<"\t.::ADMIN DASHBOARD::."<<endl;
    cout<<"1-Add Flight"<<endl<<"2-Flight tracking statistics"<<endl<<"3-Ticket confirmation"<<endl<<"4-Flight monitoring"<<endl<<"5-Log out"<<endl;
    cin>>x;
    return x;
}
int add_flight()
{
    cout<<"\t.::ADD FLIGHT::."<<endl;
    if(n_flgh_adm==10)
    {    
        cout<<"flights Are Full!(max flight you can add = 10)"<<endl;
        return n_flgh_adm;
    }
    while(1)
    {
        int n = 0, x = 1;
        cout<<"Please enter your id"<<endl;
        cin>>flight[n_flgh_adm].id;
        int q = strlen(flight[n_flgh_adm].id);
        if(strlen(flight[n_flgh_adm].id)==1 && flight[n_flgh_adm].id[0] == '0')
        {
            cout<<"ID cant be zero"<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else 
                continue;
        }
        if(q>10)
        {
            cout<<"Flight ID must be a maximum of 10 digits."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else 
                continue;    
        }
        for(int i=0; i<10; i++)
        {
            if(strcmp(flight[n_flgh_adm].id, flight[i].id)==0)
                ++n;    
        }
        if(n>1)
        {
            cout<<"The ID is duplicate"<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;
        }
        for(int i=0; i<q; i++)
        {
            if(flight[n_flgh_adm].id[i] >= '0' && flight[n_flgh_adm].id[i] <= '9');
            else
            {
                cout<<"ID digits must be between 0 and 9"<<endl;
                x = 0;
                break;
            }
        }
        if(x==1)
            break;
        if(x==0)
        {    
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;
        }
    }
    while(1)
    {
        cout<<"please enter origin"<<endl;
        cin>>flight[n_flgh_adm].origin;
        if(strlen(flight[n_flgh_adm].origin) > 50)
        {
            cout<<"the length of the phrase must be less than 50"<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;    
        }
        break;
    }
    while(1)
    {
        cout<<"please enter destination"<<endl;
        cin>>flight[n_flgh_adm].destination;
        if(strlen(flight[n_flgh_adm].destination) > 50)
        {
            cout<<"the length of the phrase must be less than 50"<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;    
        }
        break;
    }
    while(1)
    {
        cout<<"please enter year of flight"<<endl;
        cin>>flight[n_flgh_adm].date_year;
        if(flight[n_flgh_adm].date_year >= 2000 && flight[n_flgh_adm].date_year <= 3000);
        else
        {
            cout<<"flight year should be between 2000 and 3000."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;            
        }
        break;
    }
    while(1)
    {
        cout<<"please enter month of flight"<<endl;
        cin>>flight[n_flgh_adm].date_month;
        if(flight[n_flgh_adm].date_month >= 1 && flight[n_flgh_adm].date_month <= 12);    
        else
        {
            cout<<"flight month should be between 1 and 12."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;            
        }
        break;    
    }
    while(1)
    {
        cout<<"please enter day of flight"<<endl;
        cin>>flight[n_flgh_adm].date_day;
        if(flight[n_flgh_adm].date_day >= 1 && flight[n_flgh_adm].date_day <= 30);    
        else
        {
            cout<<"flight day should be between 1 and 30."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;            
        }
        break;        
    }
    while(1)
    {
        cout<<"please enter hour of flight"<<endl;
        cin>>flight[n_flgh_adm].date_hour;
        if(flight[n_flgh_adm].date_hour >= 0 && flight[n_flgh_adm].date_hour <= 23);    
        else
        {
            cout<<"flight hour should be between 0 and 23."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;            
        }
        break;
    }
    while(1)
    {
        cout<<"please enter minute of flight"<<endl;
        cin>>flight[n_flgh_adm].date_minute;
        if(flight[n_flgh_adm].date_minute >= 0 && flight[n_flgh_adm].date_minute <= 59);    
        else
        {
            cout<<"flight minute should be between 0 and 59."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;            
        }
        break;
    }
    while(1)
    {
        cout<<"please enter name of airline"<<endl;
        cin>>flight[n_flgh_adm].airline;
        if(strlen(flight[n_flgh_adm].airline) > 25)
        {
            cout<<"the length of the phrase must be less than 25."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;
        }
        break;
    }
    while(1)
    {
        cout<<"Please enter the flight capacity."<<endl;
        cin>>flight[n_flgh_adm].capacity;
        if(flight[n_flgh_adm].capacity > 250)
        {
            cout<<"The maximum flight capacity is 250 people."<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;            
        }
        flight[n_flgh_adm].capacity_remains = flight[n_flgh_adm].capacity;
        break;
    }
    n_flgh_adm++;
    cout<<"flight added successfully"<<endl;
    return n_flgh_adm;
}
int flight_trc_stat()
{
    cout<<"\t.::FLIGHT TRACKING STATISTICS::."<<endl;
    int p;
    while(1)
    {    
        int n = 0;
        cout<<"please enter id"<<endl;
        cin>>flight[10].id;
        for(int i=0; i<n_flgh_adm; i++)
        {
            if(strcmp(flight[10].id, flight[i].id) == 0)
            {
                n = 1;
                p = i;
                break;
            }
        }
        if(n == 0)
        {
            cout<<"id is not found"<<endl;
            int g = error_menu_admin();
            if(g==1)
                return 0;
            else
                continue;
        }
        if(n == 1)
            break;
    }
    //اگر تمام شرط های بالا را داشته باشد پس از بریک شدن حلقه وایل اطلاعات ان پرواز نمایان میشود
    cout<<flight[p].origin<<' '<<flight[p].destination<<' '<<flight[p].date_year<<'/'<<flight[p].date_month<<'/'<<flight[p].date_day<<' '<<flight[p].date_hour<<':'<<flight[p].date_minute<<' '<<flight[p].airline<<' '<<flight[p].capacity-flight[p].capacity_remains<<' '<<flight[p].capacity<<endl;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j < flight_user[i][0].n_b_tick; j++)
        {
            if(strcmp(flight_user[i][j].id, flight[10].id) == 0)
            {
                cout<<flight_user[i][j].name<<' '<<flight_user[i][j].name_kh<<endl;            
            }
        }   
    }
    system("pause");
    return 0;

}
int tick_conf()
{
    cout<<".::TICKET CONFIRMATION::."<<endl;
    cout<<"please enter id"<<endl;
    cin>>flight[10].id;
    cout<<"please enter username"<<endl;
    cin>>flight[10].user_user;
    for(int i=0; i<n_flgh_adm; i++)
    {
        for(int j=0; j < flight_user[i][0].n_b_tick; j++)
        {
            if(strcmp(flight_user[i][j].id, flight[10].id) == 0 && strcmp(flight_user[i][j].user_user, flight[10].user_user) == 0)
            {
                cout<<"ticket is valid"<<endl;
                system("pause");
                return 0;         
            }
        }   
    }
    cout<<"ticket is invalid"<<endl;
    system("pause");
    return 0;    
}
int flight_monitoring_adm()
{
    cout<<"\t.::FLIGHT MONITORING::."<<endl;
    //اگر اولین ایدی پرواز اول وجود نداشته باشد شرط زیر برقرار میشود
    if(flight[0].id[0] == '\0')
    {
        cout<<"Tickets not found"<<endl;
        system("pause");
        return 0;
    }
    for(int i=0; i<n_flgh_adm; i++)
    {
        cout<<flight[i].id<<' '<<flight[i].origin<<' '<<flight[i].destination<<' '<<flight[i].date_year<<'/'<<flight[i].date_month<<'/'<<flight[i].date_day<<' '<<flight[i].date_hour<<':'<<flight[i].date_minute<<' '<<flight[i].airline<<' '<<flight[i].capacity-flight[i].capacity_remains<<' '<<flight[i].capacity<<endl;                
    }
    system("pause");
    return 0;
}
int user_panel()
{
    while(1)
    {
        int code;
        cout<<"\t.::USER PANEL::."<<endl;
        cout<<"1-Login"<<endl<<"2-Signup"<<endl<<"3-Go Back"<<endl;
        cout<<"Lotfan Adad mored nazar ra vared koned:"<<endl;
        cin>>code;
        switch (code)
        {
        case 1 :
            return 1;
            break;
        case 2 :
            return 2;
            break;
        case 3 :
            return 3;
            break;    
        default:
            cout<<"Invalid Numbar|TryAgain!"<<endl;
            continue;
        }
    }    
}
int login_user_panel()
{
    int x = 0, i;
    cout<<"\t.::USER LOGIN PANEL::."<<endl;
    cout<<"Enter your username"<<endl;
    cin>>user[10].user;
    cout<<"Enter your password"<<endl;
    cin>>user[10].pass;
    for(i=0; i<10; i++)
    {
        if(strcmp(user[10].user, user[i].user) == 0 && strcmp(user[10].pass, user[i].pass) == 0)
        {    
            x = 1;
            break;
        }    
    }
    if(x == 0)
    {
        cout<<"Invalid information!"<<endl;
        cout<<"Getting back to User panel..."<<endl;
        return 0;
    }
    else
    {
        num_usr = i;
        return 1;    
    }
}
int signup_user_panel()
{
    if(n_reg_usr==10)
    {    
        cout<<"Users Are Full!(max users = 10)"<<endl;
        return n_reg_usr;
    }    
    else
    {
        cout<<"\t.::USER SIGNUP MENU::."<<endl;
        while(1)
        {
            cout<<"Enter your name"<<endl;
            cin>>user[n_reg_usr].name;
            if(strlen(user[n_reg_usr].name)>25)
            {
                cout<<"Name is too long(max=25 character)"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            else
                break;
        }            
        while(1)
        {
            cout<<"Enter your family"<<endl;
            cin>>user[n_reg_usr].name_kh;
            if(strlen(user[n_reg_usr].name_kh)>25)
            {
                cout<<"Family is too long(max=25 character)"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            else
                break;
        }        
        while(1)
        {
            int x = 1;
            cout<<"Enter your phone number"<<endl;
            cin>>user[n_reg_usr].phone;
            if(user[n_reg_usr].phone[0] != '0')
            {
                cout<<"Phone number must start with zero"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            if(strlen(user[n_reg_usr].phone) != 11)
            {
                cout<<"Phone number must have 11 digits"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }    
            for(int i=0; i<11; i++)
            {
                if(user[n_reg_usr].phone[i] >= '0' && user[n_reg_usr].phone[i] <= '9');
                else
                {
                    cout<<"Phone number digits must be between 0 and 9"<<endl;
                    x = 0;
                    break;
                }
            }
            if(x==1)
                break;
            if(x==0)
            {    
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
        }    
        while(1)
        {
            int n = 0;
            cout<<"Enter your username"<<endl;
            cin>>user[n_reg_usr].user;
            if(strlen(user[n_reg_usr].user) < 2 || strlen(user[n_reg_usr].user) > 10)
            {
                cout<<"username is too long or too short(max character=10 and min character=2)"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            for(int i=0; i<10; i++)
            {
                if(strcmp(user[n_reg_usr].user, user[i].user)==0)
                    ++n;    
            }
            //شرط پایین به دلیل این بزرگتر از 1 هست چون در بین بازه 10 تایی حلقه بالا یکبار خود یوزنیم هم دوباره تکرار میشود پس باید بیشتر از یکبار یوزرنیم تکراری باشد
            if(n>1)
            {
                cout<<"The username is duplicate"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;        
            }
            else
                break;
        }       
        while(1)
        {
            int n1=0, n2=0, n3=0;
            cout<<"Enter your password"<<endl;
            cin>>user[n_reg_usr].pass;
            int q = strlen(user[n_reg_usr].pass);
            if(q < 5 || q > 25)
            {
                cout<<"Password is too long or too short(max character=25 and min character=5)"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            for(int i=0; i<=q; i++)
            {
                if(user[n_reg_usr].pass[i] >= '0' && user[n_reg_usr].pass[i] <= '9')
                    n1++;
                if(user[n_reg_usr].pass[i] >= 'a' && user[n_reg_usr].pass[i] <= 'z')
                    n2++;
                if(user[n_reg_usr].pass[i] >= 'A' && user[n_reg_usr].pass[i] <= 'Z')
                    n3++;        
            }
            if(n1<1 || n2<1 || n3<1)
            {
                cout<<"The password must have at least one digit, one lowercase and one uppercase letter"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            else
                break;
        }        
        while(1)
        {
            cout<<"Enter your password again"<<endl;
            cin>>user[n_reg_usr].verf_pass;
            if(strcmp(user[n_reg_usr].verf_pass, user[n_reg_usr].pass)!=0)
            {
                cout<<"Password confirmation is incorrect"<<endl;
                int g = error_menu_user();
                if(g==1)
                    return 0;
                else
                    continue;
            }
            else
                break;
        }
        n_reg_usr = n_reg_usr + 1;
        cout<<"sign up is successful!"<<endl;
        return n_reg_usr;    
    }    
}
int error_menu_user()
{
    int x;
    cout<<"1-Return to your own panel"<<endl<<"2-Try Again"<<endl;
    cin>>x;
    return x;    
}
int user_dashbord()
{
    int x;
    cout<<"\t.::USER DASHBOARD::."<<endl;
    cout<<"1-Buy tickets"<<endl<<"2-Flight monitoring"<<endl<<"3-View purchased tickets"<<endl<<"4-Log out"<<endl;
    cin>>x;
    return x;
}
int buy_ticket()
{
    int n = 0; 
    cout<<"\t.::BUY TICKET::."<<endl;
    cout<<"please enter your origin"<<endl;
    cin>>flight[10].origin;
    cout<<"please enter your destination"<<endl;
    cin>>flight[10].destination;
    for(int i=0; i<n_flgh_adm; i++)
    {
        if(strcmp(flight[i].origin, flight[10].origin) == 0 && strcmp(flight[i].destination, flight[10].destination) == 0 && flight[i].capacity_remains > 0)
        {
            cout<<flight[i].id<<' '<<flight[i].date_year<<'/'<<flight[i].date_month<<'/'<<flight[i].date_day<<' '<<flight[i].date_hour<<':'<<flight[i].date_minute<<' '<<flight[i].airline<<' '<<flight[i].capacity_remains<<endl;
            n = 1;            
        }
    }    
    if(n == 0)
    {
        cout<<"There are no flights available with these specifications in the system"<<endl;
        return 0;
    }
    while(1)
    {
        cout<<"Please enter the desired flight ID(enter 0 to back to user panel)(max flight you can buy is 4)"<<endl;
        cin>>flight[10].id;
        if(flight[10].id[0] == '0' && strlen(flight[10].id) == 1)
            return 0;
        else
        {
            for(int i=0; i<n_flgh_adm; i++)
            {
                if(flight_user[num_usr][0].n_b_tick == 4)
                {
                    cout<<"you cant buy anymore!"<<endl;
                        return 0;
                }
                if(strcmp(flight[i].id, flight[10].id) == 0)
                {
                    flight[i].capacity_remains--;
                    flight_user[num_usr][flight_user[num_usr][0].n_b_tick] = flight[i];
                    //کپی کردن تمام اطلاعات پرواز برای یوزر داخل بخش خود یوزر
                    strcpy(flight_user[num_usr][flight_user[num_usr][0].n_b_tick].name, user[num_usr].name);
                    strcpy(flight_user[num_usr][flight_user[num_usr][0].n_b_tick].name_kh, user[num_usr].name_kh);
                    strcpy(flight_user[num_usr][flight_user[num_usr][0].n_b_tick].user_user, user[num_usr].user);
                    flight_user[num_usr][0].n_b_tick++;
                    cout<<"The purchase was successful."<<endl;
                    break;
                }
                if(strcmp(flight[i].id, flight[10].id) != 0 && i == n_flgh_adm - 1)
                {
                    cout<<"flight is not found"<<endl;
                    int g = error_menu_user();
                    if(g==1)
                        return 0;
                    else
                        continue;   
                }
            }
            return 0;
        }
    }    
}
int flight_monitoring()
{
    cout<<"\t.::FLIGHT MONITORING::."<<endl;
    for(int i=0; i<n_flgh_adm; i++)
    {
        if(flight[0].id[0] == '\0')
        {
            cout<<"Tickets are not available for purchase"<<endl;
            return 0;
        }
        else
        {
            if(flight[i].capacity_remains != 0)
            {
                cout<<flight[i].id<<' '<<flight[i].origin<<' '<<flight[i].destination<<' '<<flight[i].date_year<<'/'<<flight[i].date_month<<'/'<<flight[i].date_day<<' '<<flight[i].date_hour<<':'<<flight[i].date_minute<<' '<<flight[i].airline<<' '<<flight[i].capacity_remains<<endl;                
            }
        }
    }
    system("pause");
    return 0;
}
int view_purchased_tickets()
{
    cout<<"\t.::VIEW PURCHASED TICKETS::."<<endl;
    if(flight_user[num_usr][0].n_b_tick == 0)
    {
        cout<<"You did not buy a flight"<<endl;
        system("pause");
        return 0;
    }
    else
    {
        for(int i=0; i<flight_user[num_usr][0].n_b_tick; i++)
        {
            cout<<flight_user[num_usr][i].id<<' '<<flight_user[num_usr][i].origin<<' '<<flight_user[num_usr][i].destination<<' '<<flight_user[num_usr][i].date_year<<'/'<<flight_user[num_usr][i].date_month<<'/';
            cout<<flight_user[num_usr][i].date_day<<' '<<flight_user[num_usr][i].date_hour<<':'<<flight_user[num_usr][i].date_minute<<' '<<flight_user[num_usr][i].airline<<endl;
        }
        system("pause");
        return 0;
    }    
}