/* ---------------------------------------------------------------------------*
 * file:        webcert.h                                                     *
 * purpose:     provide standard definitions accross cgi's                    *
 * author:      03/04/2004 Frank4DD                                           *
 * ---------------------------------------------------------------------------*/

#include "openssl/asn1.h"
#include "openssl/bn.h"

/*********** the main URL where the webcert application resides ***************/
#define HOMELINK	"/sw/webcert/"
/*********** the application entry URL which is seen first ********************/
#define REQLINK		"/sw/webcert/cgi-bin/certrequest.cgi"
/*********** where is the ca certificate .pem file ****************************/
#define CACERT 		"/srv/app/webCA/cacert.pem"
/*********** where is the ca's private key file *******************************/
#define CAKEY           "/srv/app/webCA/private/cakey.pem"
/*********** The password for the ca's private key ****************************/
#define PASS            "webca-secret"
/*********** The directory where the generated certificates are stored ********/
#define CACERTSTORE	"/srv/app/webCA/certs"
/*********** The directory to write the exported certificates into ************/
#define CERTEXPORTDIR   "/srv/www/std-root/frank4dd.com/sw/webcert/export"
/*********** The export directory URL to download the certificates from *******/
#define CERTEXPORTURL   "/sw/webcert/export"
/*********** where the ca's serial file is ************************************/
#define SERIALFILE      "/srv/app/webCA/serial"
/*********** certificate lifetime *********************************************/
#define DAYS_VALID      1095
#define YEARS_VALID     3

/* For the public demo, I enforce adding the source IP to the certificate CN */
/* For internal use, you could take it out. */
/* #define FORCE_SOURCE_IP_INCLUSION	TRUE */

/***************** *********************************** ************************/
/***************** no changes required below this line ************************/
/***************** *********************************** ************************/

#define CONTACT_EMAIL	"support@frank4dd.com"
#define SW_VERSION	"WebCert v1.7.4 (21/06/2011)"

/*********** html code template for populating the sidebar  *******************/
#define SIDEBAR_TEMPL	"../sidebar-template.htm" /* optional */
/*********** html code template for populating the help data  *****************/
#define HELP_TEMPL	"../help-template.htm" /* mandatory */
/*********** html code template for populating the policy text  ***************/
#define POLICY_TEMPL	"../policy-template.htm" /* mandatory */
/****** html code template for adding code or scripts into the footer *********/
#define FOOTER_TEMPL	"../footer-template.htm" /* optional */

#define REQLEN		4096 /* Max length of a certificate request in bytes.*/
                             /* Often not bigger then 817 bytes with a 1024  */
			     /* bit RSA key, size increases for bigger keys  */
			     /* and when a lot of attributes are generated.  */

#define KEYLEN          4096 /* this is the max length of a private key in   */
                             /* PEM format used for the PKCS12 cert bundle   */
                             /* generation.                                  */

#define P12PASSLEN      41   /* this is the max length for the password used */
                             /* as protection for the PKCS12 cert bundle.    */

#define MAXCERTDISPLAY	8    /* # of certs that will be shown in one webpage */

#define int_error(msg)  handle_error(__FILE__, __LINE__, msg)

void pagehead(char *title);
void pagefoot();
void handle_error(const char *file, int lineno, const char *msg);
//ASN1_INTEGER *x509_load_serial(char *CAfile, char *serialfile, int create);
BIGNUM *load_serial(char *serialfile, int create, ASN1_INTEGER **retai);
int save_serial(char *serialfile, char *suffix, BIGNUM *serial, ASN1_INTEGER **retai);

#define EXPIRE_SECS     (60*60*24*DAYS_VALID)

/****************************** end webcert.h *********************************/
