/*
 * FUN_00406940 at 00406940
 * undefined FUN_00406940(void)
 * Address ranges: 00406940-00406b37
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406940(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 local_c8 [200];
  
  if ((DAT_0053b9e0 != 0) && (DAT_0053b9bc != 0)) {
    if (DAT_0053a4a0 != 0) {
      cVar1 = FUN_00417e90(param_1);
      iVar2 = DAT_0053be60;
      if (cVar1 == '\0') {
        iVar2 = (&DAT_005081b8)[param_1 * 0x1c];
      }
      cVar1 = FUN_00406bb0(param_1);
      FUN_004be8cb(local_c8,200,s_R_d___4d___4d__c__004de864,param_1,(&DAT_00503ef4)[param_1 * 0x47]
                   ,iVar2 + 1,(int)cVar1);
      FUN_004b1850(0,0,param_1 * 0x1e + 0x14,local_c8);
    }
    switch((&DAT_00503ef4)[param_1 * 0x47]) {
    case 0:
      FUN_0040e490(param_1);
      break;
    case 1:
      FUN_00409cc0(param_1);
      break;
    case 2:
      FUN_00409dc0(param_1);
      break;
    case 3:
      FUN_0040e4a0(param_1);
      break;
    case 4:
      FUN_00409fe0(param_1);
      break;
    case 5:
      FUN_0040a3b0(param_1);
      break;
    case 6:
      FUN_0040a4d0(param_1);
      break;
    case 7:
      FUN_0040a690(param_1);
      break;
    case 8:
      FUN_0040a550(param_1);
      break;
    case 9:
      FUN_00409ea0(param_1);
      break;
    case 10:
      FUN_0040e4b0(param_1);
      break;
    case 0xb:
      FUN_0040a2b0(param_1);
      break;
    default:
      FUN_004afee0(s_Illegal_state__Function__HandleA_004de878);
      break;
    case 0xe:
      FUN_0040ab70(param_1);
      break;
    case 0xf:
      FUN_0040aa90(param_1);
      break;
    case 0x10:
      FUN_0040a730(param_1);
      break;
    case 0x11:
      FUN_0040a950(param_1);
      break;
    case 0x13:
      FUN_0040adf0(param_1);
      break;
    case 0x16:
      FUN_0040e460(param_1);
      break;
    case 0x17:
      FUN_0040e660(param_1);
      break;
    case 0x18:
      FUN_0040e6c0(param_1);
      break;
    case 0x19:
      FUN_0040e6d0(param_1);
      break;
    case 0x1a:
      FUN_0040e690(param_1);
      break;
    case 0x1b:
      FUN_0040e270(param_1);
      break;
    case 0x1c:
      FUN_0040e730(param_1);
    }
    if (-1 < (int)(&DAT_00503ef0)[param_1 * 0x47]) {
      FUN_00409530(param_1);
    }
    if (param_1 < DAT_00508610) {
      FUN_004067e0();
    }
    else {
      FUN_00406880(param_1);
    }
    if ((&DAT_00503ef4)[param_1 * 0x47] != 10) {
      FUN_004062b0(param_1);
    }
  }
  return;
}

