#ifndef CLASSES_H
#define CLASSES_H

class base {

    public:
        base();
        base(int pfield_value, int prtfield_value, int privfield_value);
        base(base& other);
        virtual ~base();
        virtual int get_public_value();
        virtual int get_protected_value();
        virtual int get_private_value();
        virtual int set_public_value(int new_value);
        virtual int set_protected_value(int new_value);
        virtual int set_private_value(int new_value);

        int public_field;

    protected:
        int protected_field;

    private:
        int private_field;

};

class derived_public: public base {

    public:
        derived_public();
        derived_public(int pfield_value, int prtfield_value, int privfield_value);
        derived_public(derived_public& other);
        virtual ~derived_public();
        int get_public_value();
        int get_protected_value();
        int get_private_value();
        int set_public_value(int new_value);
        int set_protected_value(int new_value);
        int set_private_value(int new_value);

};

class derived_protected: protected base {

    public:
        derived_protected();
        derived_protected(int pfield_value, int prtfield_value, int privfield_value);
        derived_protected(derived_protected& other);
        virtual ~derived_protected();
        int get_public_value();
        int get_protected_value();
        int get_private_value();
        int set_public_value(int new_value);
        int set_protected_value(int new_value);
        int set_private_value(int new_value);

};

class derived_private: private base {

    public:
        derived_private();
        derived_private(int pfield_value, int prtfield_value, int privfield_value);
        derived_private(derived_private& other);
        virtual ~derived_private();
        int get_public_value();
        int get_protected_value();
        int get_private_value();
        int set_public_value(int new_value);
        int set_protected_value(int new_value);
        int set_private_value(int new_value);

};

#endif