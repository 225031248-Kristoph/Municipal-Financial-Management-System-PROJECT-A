#ifndef SUPPLIERS_H
#define SUPPLIERS_H


#ifndef MAX_SUPPLIERS
#define MAX_SUPPLIERS 100
#endif
#define SUP_ID_LEN     16
#define SUP_NAME_LEN   64
#define SUP_EMAIL_LEN  64
#define SUP_PHONE_LEN  24
#define SUP_TOWN_LEN   48

typedef struct {
    char id[SUP_ID_LEN];
    char name[SUP_NAME_LEN];
    char email[SUP_EMAIL_LEN];
    char phone[SUP_PHONE_LEN];
    char town[SUP_TOWN_LEN];
} Supplier;


void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);


int      getSupplierCount(void);
Supplier getSupplier(int index); 

#endif