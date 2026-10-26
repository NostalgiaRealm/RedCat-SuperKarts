/*
 * FUN_00429550 at 00429550
 * undefined FUN_00429550(void)
 * Address ranges: 00429550-004295cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429550(void)

{
  char *pcVar1;
  
  switch(DAT_004e7b70) {
  case 0:
  case 1:
  case 2:
  case 5:
    FUN_004b25a0(s_Pallow_pcx_004e7bc4,1);
    pcVar1 = s_loading_lowres_pallet__s_004e86a0;
    break;
  case 3:
  case 4:
  case 6:
    FUN_004b25a0(s_Palhigh_pcx_004e7bd4,1);
    pcVar1 = s_loading_hires_pallet__s_004e86bc;
    break;
  default:
    goto switchD_0042955a_default;
  }
  FUN_004afce0(pcVar1,s_Pallow_pcx_004e7bc4);
switchD_0042955a_default:
  FUN_004afce0(s_Locking_Pallette_004e86d8);
  FUN_004b2340(DAT_006ab468,0,0xff);
  FUN_004b24c0(DAT_006ab468,0,0xff,0x40,1);
  return;
}

