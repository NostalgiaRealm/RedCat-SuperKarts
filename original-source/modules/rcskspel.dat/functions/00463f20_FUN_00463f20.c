/*
 * FUN_00463f20 at 00463f20
 * undefined FUN_00463f20(void)
 * Address ranges: 00463f20-00463f98;00463f9a-00463fa0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463f20(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_84;
  char local_80 [128];
  
  FUN_004b2110(param_1,local_80,0x7f);
  iVar2 = FUN_004bf458(local_80,&DAT_004f4050,param_2);
  if (iVar2 != 0) {
    return;
  }
  iVar2 = -1;
  pcVar3 = local_80;
  do {
    pcVar4 = pcVar3;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar4;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar4 + -1) = s___Bad_float_004f4054._0_4_;
  *(undefined4 *)(pcVar4 + 3) = s___Bad_float_004f4054._4_4_;
  local_84 = local_80;
  *(undefined4 *)(pcVar4 + 7) = s___Bad_float_004f4054._8_4_;
  pcVar4[0xb] = s___Bad_float_004f4054[0xc];
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_84,&DAT_004d5538);
}

