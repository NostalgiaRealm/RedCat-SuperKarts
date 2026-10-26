/*
 * FUN_004576b0 at 004576b0
 * undefined FUN_004576b0(void)
 * Address ranges: 004576b0-00457720
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004576b0(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_00417e90(param_2);
  iVar3 = DAT_0053be28;
  if (cVar1 == '\0') {
    iVar3 = (&DAT_005081bc)[param_2 * 0x1c];
  }
  iVar2 = 0;
  if (0 < DAT_00508610 + 1) {
    do {
      if (((char)param_1[3] != '\0') && (*param_1 == iVar3)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 4;
    } while (iVar2 < DAT_00508610 + 1);
  }
  FUN_004afce0(s__s__d____Error_finding_bubble_ob_004f2390,
               s_D__work_rcsk_Code_game_rcr_bubbl_004f2360,0x6a,param_2);
  return -1;
}

