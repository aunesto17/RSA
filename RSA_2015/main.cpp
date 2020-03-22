//
//  main.cpp
//  RSA_2015
//
//  Created by Alexander Arturo Baylon Ibanez on 5/18/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "rsa.h"

int main(int argc, const char * argv[]) {
    /*
    ZZ base(48);
    ZZ exp(5);
    ZZ mod(91);
    //cout << mod_n(base, exp) << endl;
    //cout << expo_rap(base, exp, mod) << endl;
    string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890,;:-_<>@*+().";
    cout << "tam: alfa: "<< alfa.size() << endl;
    
    string msj0 = "Aunque el termino criptografia nos suele hacer pensar en el mundo de los espias y en agencias como la NSA, realmente esta muy presente en nuestro dia a dia. Cuando nos conectamos a servicios como Gmail, estamos estableciendo una comunicacion segura y, por tanto, cifrada entre nuestro ordenador (o nuestro dispositivo movil) y los servidores de Google. Cuando realizamos una llamada telefonica desde nuestro terminal movil, la secuencia de datos que generamos tambien esta cifrada y, de esta forma, se evita que alguien no autorizado pueda estar a la escucha e interceptar nuestras comunicaciones.";
    
     string msj = "Aunque el termino criptografia nos suele hacer pensar en el mundo de los espias y en agencias como la NSA, realmente esta muy presente en nuestro dia a dia. Cuando nos conectamos a servicios como Gmail, estamos estableciendo una comunicacion segura y, por tanto, cifrada entre nuestro ordenador (o nuestro dispositivo movil) y los servidores de Google. Cuando realizamos una llamada telefonica desde nuestro terminal movil, la secuencia de datos que generamos tambien esta cifrada y, de esta forma, se evita que alguien no autorizado pueda estar a la escucha e interceptar nuestras comunicaciones.a criptografia se encarga, precisamente, de cifrar o codificar mensajes para evitar que su contenido pueda ser leido por un tercero no autorizado; es decir, la generacion de codigos y algoritmos de cifrado que buscan ofuscar la informacion y protegerla de ojos curiosos es el cometido principal de esta disciplina. La criptografia es una de las areas que componen la criptologia; su mision es mucho mas amplia y tambien se ocupa del criptoanalisis, es decir, romper las codificaciones realizadas por terceros (como ejemplo podemos tomar a la NSA o los descifradores de codigos de la Segunda Guerra Mundial), la esteganografia (la ocultacion de mensajes dentro de canales inseguros de manera que pasen desapercibidos) y el estegoanalisis, que busca, precisamente, detectar los mensajes ocultos mediante esteganografia.La criptografia ha hecho cambiar el curso de conflictos como la Segunda Guerra Mundial y el criptoanalisis se ha convertido en una potente arma que muchos Gobiernos usan para conseguir ventaja tactica y acceder a fuentes de informacion de lo mas diversa. Las comunicaciones estan sometidas cada vez a mayor escrutinio por parte de los Gobiernos y las revelaciones de Edward Snowden sobre los programas de espionaje masivo de la NSA nos han hecho ver la criptografia y las puertas traseras de una manera distinta. Con la idea de entender mejor en que consiste la criptografia y como ha evolucionado esta disciplina hasta nuestros dias, vamos a echar una mirada atras en el tiempo para conocer la historia de la criptografia y el cifrado de la informacion.Los origenes de la criptografia Aunque pensemos en Alan Turing, Claude Shannon o la NSA como referentes en el campo de la criptografia (y, por cierto, lo son), este arte se remonta mucho mas atras en el tiempo. El cifrado de mensajes se lleva practicando desde hace mas de 4.000 aÒos y, precisamente, el origen de la palabra criptografia lo encontramos en el griego: krypto, oculto, y graphos, escribir; es decir, escritura oculta.Una comunicacion esta cifrada cuando solamente emisor y receptor son capaces de extraer la informacion del mensaje; por tanto, cualquier persona ajena a la comunicacion solamente sera capaz de ver un galimatias sin sentido y el contenido del mensaje le quedara totalmente oculto.Aunque los jeroglificos del Antiguo Egipto no tenian una intencion militar, suelen tomarse como uno de los primeros ejemplos de escritura oculta de la historia (se necesito la Piedra de Rosetta para descrifrarlos). Existen jeroglificos no estandares que, segun los expertos, tenian como objetivo dotar de mayor dramatismo a la historia que se representaba; estas inclusiones buscaban dotar de mayor misterio o intriga al relato descrito y complicaban la lectura con la inclusion de simbolos no usuales (aunque la practica se abandonaria con el tiempo).La Biblia (concretamente en el libro de Jeremias) hace referencias al Atbash, un sistema de sustitucion de letras que se usaba para cifrar mensajes y que se remonta al aÒo 600 a.C.; sobre esta misma epoca tambien se encontraron ejemplos de cifrado de mensajes por sustitucion en los reinos Mahajanapadas de la India.Si miramos hacia la Antigua Grecia, en la Iliada de Homero podemos encontrar una referencia al uso del cifrado de mensajes. Belerofonte, heroe mitologico, entrega al rey Iobates de Licia una carta cifrada por el rey Preto de Tirinto; el contenido de la carta es secreto y esta cifrada pero el mensaje esconde que se debe dar muerte al portador de la misma, Belerofonte. Los espartanos tambien usaban la criptografia para proteger sus mensajes; concretamente, una tecnica conocida como cifrado por transposicion que consistia en enrollar un pergamino sobre una estaca (llamada escitala) que servia para ordenar las letras y mostrar el mensaje. Para poder descifrarlo, el receptor debia contar con una escitala del mismo diametro que la que habia usado el emisor (criptografia simetrica) porque era la unica forma de visualizar el mensaje de la misma forma.De la Antigua Roma procede el conocido como cifrado Cesar que, como bien indica su nombre, su uso se atribuye al mismo Julio Cesar. Este cifrado se basa en el desplazamiento de letras y, por tanto, cada letra del texto original se sustituye por otra letra que se encuentra un numero fijo de posiciones mas adelante en el alfabeto. Segun los escritos del historiador romano Suetonio, Julio Cesar usaba un desplazamiento de 3 letras y Augusto, primer emperador y sobrino-nieto de Julio Cesar, usaba un desplazamiento de una letra.";
    
    string cifradoChino = "1423159266684734622240524634114109547780483862141656240484623622274985983679301639993286217228625743534144182958872721918773764179964085540488594728184998371702190527744984792123280516745490041411120404186237099773597986862579835740180003385291886081389917146248323538579101763099823552119318365268964189786992750094971145193215081347582168735498199601742359814812435207059911852587073408121418670747398237146815117128090747702240505420746922955204410028584664891154510174649166074031239115121347536657414070397660227727040177988888169076257129181895924974987433572463101784712919374290127149274991807052616325211542037104840725257507028602122665581227148141814301048207821761553980572377373931899514240606807699730602049420110393687602639601677803653576768328576238251617206988101473788265247261191410536067824025111570585970881997317050216444351811733211901707411509095169612897899070916715516700199569534941513081475814576104136955491414217203107167334123224568491733209061200521503466148009162276874897022857451485270326994799427169359920752175551800427849988624386635987523810054247503841235717700713378965521905932133878924821587492495831179645979563495366956427771563729479752102213570746203653229388271123743941024929508934344293137462365830280776678772100606095617711675118256151544646515062313630531473980173097789801345073091973726658820773257824970297261450120817100607095981219005047562697281164562839096399767585236304405237456300457172006076196938879896891198030188620203060191558786661411500846653139169090569539084900855247555721286478271271850808323781988759476747013708035696094550338049099066512958583105839048770050951781406793121513694823138273832720906941094331293681536651697006163790395568300277277467217762582388430040935777852920162502866802043737933997407670863007451589894642242169891379983779872420052891692737734283884963700144094363416342880423897562679538815946192455261303117190524222835810759505464864255218814359300257444035453315766414830610028949231761633810712089421944279737668925679129080346924486925414560926114761646896769960704619044330245126950900003893159172070221553020318719882284661426916041221550430199243031922157244163603620417759990603346058372302633257388919050433412241001806180679808350002804390274024102330189339298289821847519212417376826237300820004208772850776545654866534814417630535181923981289852965370276726329148620484538663973911902494381717388179800120049542654372591741149062044432301616040641642816819463775608611500286459624531171746583952266753761788962261200095121542396523476148227461296778140432333621528511837039657404067629131180598998911399140670348392532478102492232900656101856114456420008078812451042925831799730027329152311505405477237785416885575601034706171540367449195438985300663334261614366442902191640814615230060251695980403189351953515873599043056028862516781119673323430759027358031480798328819141131195582661184143688166631063777331001888339091645216553681149239790162299690919103137773425199940435547625484057720078376729709786743453130027530912064680255537823172786549088340571442594012811785207428601588273946211416995344024621368554951220742940588700384094590675631423917309831890263764807783580218310561495942828998898413795782810963961162991149028394649237744027090349065546224201284002275879082617122084426306996644891762334631942223179586745921366244667411668269882496745378105702150005385729641515147142902987966188031448916498356271044909382793942237712582211601922386071939777856686512969880854575110574312350701863909305387275129951373711787170410544639564523613141730260920993777251600276698554827556712353445513028867130420567248278229448948173325673884910569221501506069742006252923434913416614050890069379104983944610475966317792938110820581701000354749670344940848235839855010046289229688301696323750899852308296360771791111758828889421951957514895564650747894975501336137552608074873836569381689446636683901310970340339523512506260629808254333437735689659854006115876411144685918231375893695180491708588344670219331181805659002271389235397976163561146357530555886805458053041003403272720346138445653257325351847130092600601771901738255207985840760364671704513678571191264310159820160866692441381254813670832631672080603768556322968484015494041507900647370626033677785775472366953281484195166087860134149694062622216033211933293221800555286146740961180631658250113903336026469813425848339659977045651223352771298822654779759800320344349661485157795836963225491813242548647875300918134432221434456512753406609127359070070555782976876644859493874146169835310572121192823835992796464372559020834281950026813506046996483414666190753629221640349651306987947522304843182920229831866868574895695164886466809490876958300982816217876325937904329915895375370091300558826869258047045715365755836332070593641205706435052228407538933343201910772869570697341470702921278297756621880015642964065712475355568209035515861401243832714885479690614243261215481303560258729904101257090606173896926478000811274524608739521595182994052495544393341941349990949371169641377405139017584620084598742139189419054488449573783202981442170523352171407041755961632701618701441699127085125678134964884654658608380567928268182551766550886540974560680951013915998746428856647724782475011138890767046373912296534048259211459909109200541159330441502160537153648494286529701349411802790093085288668534490528395490264048223776737975410430983862464900260115066153024953780787199428346770504181699663158389767419181933453628863492681851658939184367484058786138040132419451119771249400236468358621748901400078480115487152778952030845733185857807294571666630031221604075899657725452416992880309652288595661484785397728251681036550611963364501792624160041329064470528551680152390336427924639586312631440579060191301973693584224847646848712233205580345201621040685361720435743054962377160940495769953420989902212881081140265430318835976121599995807983649764448144481584836628217678724475134450401774308591276011255527078578335485952521307828071636765126433633474371828451552926206881176932550741988068523809516595305240091770550170767295527667775624603706907981147925164371771867530222345931623403551726362632090238626200059732315044341611622623428979082041737127258318403586610585319322920959993924926666050112124341553321013477083893402234851061937548400304073339106400432349646112823224524731053022400359726923573913378557853165741969589546321467246526922953369415367650986427363503188454786712933568291023900386004565835357360683191656987328670251112386279900115088955104026338659970860899720029368595096160074270683310762410475782748236332399341681291555188273550748026813134278632100248525729693838101000682970865445416059017411075707272811405358731930839781694496494095217753231689957107368272327260368669328782390401830841845389419543037184688409663576910589769872762192889546994392099024858221626327106218326462342840826414103126180204699658596556831928511831175302020710904058260707074984869193640759095222891896968608484184715114469723773484860100090371000882106523423879097925658743930004335486256109677087893051726070023051480645041016497280780425348079867878700323609431260918040505648291040778663050603608093096689645892269189976969243330006712556779706814281758461102149726330617616835448476073410716234731746649940136904385937460866751840347225405898860670567880259601495743927181382951333841080104813165166183185177466064735334861625547420388198839340436745937472532841225160072346287175711382153029325726181503603277657949109429925594523267438080911599277770301943447698445273422040470737391000106461872149893726613603979891775625827552551600794463998666526641360041084403925752473987015686807362494080053473077441863871631211751385619287460020633654647034222241911047977605223750660645410104238557772217416148804482951547516433791954948299311889373782999441803236909111680016414876781569727941281817080302812406499856407119813596370671811297707930459239749305295043837920511617335442722819566961410577733502732140983953805788936848438260039821167932941605000589075659690530301501071194446761179781666870933918200466024275784169530853593938544673341649344617339948549331611421394029845297600520623586418743450182707235268042675431133083581283240251942391697072099620681859957780569102811515537010756649580656919729440393799501132286544971520861414889998307370667660778682209617297530836957139382087319740734994417298543928335347898382750920321135163688954134556639331157434893838311042526130213539890036560626428779000771262614339156037826118774997980879452331641555475738174372852336175483142384350604743674093157255424562536840982355771840642315024125528281278915739528540220955329954323638230175475490299009390810580955998229564219913566308007710251150423814272678837505172351946708947316550061218610328960797453748894061354972221758074011949509281033049547358661219661415449811910512276851803316295152189530283969502930552938163741663371834658120341046824960050868357884262205598052140189076472556965363086489335309147898251282161025376987614043761805612682304961366699791086808123352463461534083883601466252527967911173278195444979663422011365873992807041075684523518586928065631263239815969070456882668828702706571470903249450587231682799908173438467116970437402059216608245112599099506096383150050356534143612093104045649429320317811570232792148374543691902036359198172190470949211295908462986502775877302945570275746493212644406816214844394617065910651263560083299734429326798437391271660837157653368269248831104515228389894441247348525992740041296674319027598404020206571924396850338502785160311536403510444294027288567017498562914463541409640753934760494247048486277290975820339870559586809111533602869737884516659426161034568523930615383643075932623525135870124112193363955782784864390874183539300444230349632966158791278999265643074860595725855418039278504856548201774571860026358379149758981307176021134029263881036119993242138141898962173351802900440800783717477689854480381289201398021031897390004230999150389014618005719558060768147291417023872945475871420576206370610089686655592868046022097668123796131341345570074322604663598125229378471371066138964880237557775354139509833288461135159147073732359578270764583745964761488567177083085652918194773716015192430839110641346084523810137719853127299540204527554882371065098977487689919520381440595564987699074657268397954230019091580446288114538733676583392678482366480802241624751242580747207331835462640950774070579361945775453420236425046582260555376104250240704950222669175310392710176873111849987403765422515695586578427";
    
    cout << alfa.size() << endl;

    rsa prueba(128,101);
    
    string cifrado0 = prueba.cifrado(msj);
    cout << "des: " << endl << cifrado0 << endl;
    
    string cifrado1 = prueba.decifrado(cifrado0);
    cout << "des: " << endl <<cifrado1 << endl;
    
    
    
    //string cifch = prueba.cifrado(msj0);
    //cout << "fabri:" << endl << cifch << endl;
    
    */
    /*
    string tmp = prueba.cifrado(ms);
    cout << "cif.fin: " << tmp << endl;
    
    tmp = prueba.decifrado(tmp);
    cout << "dec.par: " << tmp << endl;
    */
    /*
    LFSR temp1(1024);
    base = temp1.getNum();
    cout << base << endl;
    cout << SqrRoot(base) << endl;
    
    vector<int> tmp2 = cribaEratostenes(base);
    for (int c : tmp2){
        cout << c << " ";
    }
    */
    
    string msj0 = "Aunque el termino criptografia nos suele hacer pensar en el mundo de los espias y en agencias como la NSA, realmente esta muy presente en nuestro dia a dia. Cuando nos conectamos a servicios como Gmail, estamos estableciendo una comunicacion segura y, por tanto, cifrada entre nuestro ordenador (o nuestro dispositivo movil) y los servidores de Google. Cuando realizamos una llamada telefonica desde nuestro terminal movil, la secuencia de datos que generamos tambien esta cifrada y, de esta forma, se evita que alguien no autorizado pueda estar a la escucha e interceptar nuestras comunicaciones.a criptografia se encarga, precisamente, de cifrar o codificar mensajes para evitar que su contenido pueda ser leido por un tercero no autorizado; es decir, la generacion de codigos y algoritmos de cifrado que buscan ofuscar la informacion y protegerla de ojos curiosos es el cometido principal de esta disciplina. La criptografia es una de las areas que componen la criptologia; su mision es mucho mas amplia y tambien se ocupa del criptoanalisis, es decir, romper las codificaciones realizadas por terceros (como ejemplo podemos tomar a la NSA o los descifradores de codigos de la Segunda Guerra Mundial), la esteganografia (la ocultacion de mensajes dentro de canales inseguros de manera que pasen desapercibidos) y el estegoanalisis, que busca, precisamente, detectar los mensajes ocultos mediante esteganografia.La criptografia ha hecho cambiar el curso de conflictos como la Segunda Guerra Mundial y el criptoanalisis se ha convertido en una potente arma que muchos Gobiernos usan para conseguir ventaja tactica y acceder a fuentes de informacion de lo mas diversa. Las comunicaciones estan sometidas cada vez a mayor escrutinio por parte de los Gobiernos y las revelaciones de Edward Snowden sobre los programas de espionaje masivo de la NSA nos han hecho ver la criptografia y las puertas traseras de una manera distinta. Con la idea de entender mejor en que consiste la criptografia y como ha evolucionado esta disciplina hasta nuestros dias, vamos a echar una mirada atras en el tiempo para conocer la historia de la criptografia y el cifrado de la informacion.Los origenes de la criptografia Aunque pensemos en Alan Turing, Claude Shannon o la NSA como referentes en el campo de la criptografia (y, por cierto, lo son), este arte se remonta mucho mas atras en el tiempo. El cifrado de mensajes se lleva practicando desde hace mas de 4.000 anos y, precisamente, el origen de la palabra criptografia lo encontramos en el griego: krypto, oculto, y graphos, escribir; es decir, escritura oculta.Una comunicacion esta cifrada cuando solamente emisor y receptor son capaces de extraer la informacion del mensaje; por tanto, cualquier persona ajena a la comunicacion solamente sera capaz de ver un galimatias sin sentido y el contenido del mensaje le quedara totalmente oculto.Aunque los jeroglificos del Antiguo Egipto no tenian una intencion militar, suelen tomarse como uno de los primeros ejemplos de escritura oculta de la historia (se necesito la Piedra de Rosetta para descrifrarlos). Existen jeroglificos no estandares que, segun los expertos, tenian como objetivo dotar de mayor dramatismo a la historia que se representaba; estas inclusiones buscaban dotar de mayor misterio o intriga al relato descrito y complicaban la lectura con la inclusion de simbolos no usuales (aunque la practica se abandonaria con el tiempo).La Biblia (concretamente en el libro de Jeremias) hace referencias al Atbash, un sistema de sustitucion de letras que se usaba para cifrar mensajes y que se remonta al aÒo 600 a.C.; sobre esta misma epoca tambien se encontraron ejemplos de cifrado de mensajes por sustitucion en los reinos Mahajanapadas de la India.Si miramos hacia la Antigua Grecia, en la Iliada de Homero podemos encontrar una referencia al uso del cifrado de mensajes. Belerofonte, heroe mitologico, entrega al rey Iobates de Licia una carta cifrada por el rey Preto de Tirinto; el contenido de la carta es secreto y esta cifrada pero el mensaje esconde que se debe dar muerte al portador de la misma, Belerofonte. Los espartanos tambien usaban la criptografia para proteger sus mensajes; concretamente, una tecnica conocida como cifrado por transposicion que consistia en enrollar un pergamino sobre una estaca (llamada escitala) que servia para ordenar las letras y mostrar el mensaje. Para poder descifrarlo, el receptor debia contar con una escitala del mismo diametro que la que habia usado el emisor (criptografia simetrica) porque era la unica forma de visualizar el mensaje de la misma forma.De la Antigua Roma procede el conocido como cifrado Cesar que, como bien indica su nombre, su uso se atribuye al mismo Julio Cesar. Este cifrado se basa en el desplazamiento de letras y, por tanto, cada letra del texto original se sustituye por otra letra que se encuentra un numero fijo de posiciones mas adelante en el alfabeto. Segun los escritos del historiador romano Suetonio, Julio Cesar usaba un desplazamiento de 3 letras y Augusto, primer emperador y sobrino-nieto de Julio Cesar, usaba un desplazamiento de una letra.";
    
    menuPrincipal();
    //ifstream entrada("directorioElectronico.txt");
    unsigned int bits = ingresar("bits");
    unsigned int modAlfa = ingresar("modificador de alfabeto");
    rsa maestro(bits,modAlfa);
    
    //ifstream entrada("directorioElectronico.txt");
    ifstream entrada("directorioNoob.txt");
    vector<string>claveE;
    vector<string>claveN;
    string a,b,c;
    while (entrada >> a >> b) {
        claveN.push_back(a);
        claveE.push_back(b);
    }
    
    /*
    for(int i = 0; i < claveE.size(); i++) {
        cout << "e: " << claveE[i] << endl;
        cout << "N: " << claveN[i] << endl;
    }*/
    
    // Cifrar los mensajes con las distintas claves.
    vector<string>mensajes_cif;
    for (int i=0; i < claveE.size(); i++) {
        mensajes_cif.push_back(maestro.nuevoMensaje(claveN[i], claveE[i], msj0));
    }
    cout << "MENSAJES CIFRADOS PARA ENVIAR: " << endl;
    for (int j=0; j<mensajes_cif.size(); j++) {
        cout << mensajes_cif[j] << endl << endl;
    }
    ofstream outfile("cifradosEnviar.txt");
    for (int k=0; k<mensajes_cif.size(); k++) {
        outfile << mensajes_cif[k] << endl << endl;
    }
    
    
    /*
    //Decifrar los mensajes recibidos.
    ifstream recibidos("mensajesRecibidos.txt");
    vector<string>mensajes_res;
    while (recibidos >> c) {
        mensajes_res.push_back(c);
    }
    
    cout << "MENSAJES RECIBIDOS: " << endl;
    for (int n=0; n<mensajes_res.size(); n++) {
        cout << mensajes_res[n] << endl;
    }
    
    vector<string>mensajes_desencriptados;
    cout << "numero de mensajes recibidos: " << mensajes_res.size() << endl;
    for (int m=0; m<mensajes_res.size(); m++) {
        mensajes_desencriptados.push_back(maestro.recibirMensaje(claveN[m], claveE[m], mensajes_res[m]));
    }
    
    ofstream outfile1("mensajesOriginales.txt");
    for (int o=0; o<mensajes_desencriptados.size(); o++) {
        outfile1 << mensajes_desencriptados[o] << endl;
    }
     */
    
    
    /*
    for (int n=0; n<mensajes_desencriptados.size(); n++) {
        cout << mensajes_desencriptados[n] << endl;
    }
    */
    
    
    /*
    string cifDen = maestro.nuevoMensaje("16848994587010388903", "136585531864725362802109525425037413449",msj0);
    
    cout << "cifden: " << cifDen << endl;
    
    */
    return 0;
}
