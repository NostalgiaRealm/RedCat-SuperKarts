/*
 * FUN_004500e0 at 004500e0
 * undefined FUN_004500e0(void)
 * Address ranges: 004500e0-004501ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004500e0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *local_cc;
  undefined1 local_c8 [199];
  undefined1 local_1;
  
  if (DAT_00543d1c == '\0') {
    FUN_004506f0();
  }
  if ((&DAT_004f0fb8)[*param_1] == -1) {
    uVar2 = FUN_004500b0();
    FUN_004be8cb(local_c8,199,s_Illegal_animation_in_CBonusData__004f109c,uVar2);
    local_cc = local_c8;
    local_1 = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_cc,&DAT_004d5538);
  }
  if (0 < param_1[5]) {
    iVar1 = (&DAT_004f0fb8)[*param_1] * 9;
    puVar4 = (undefined4 *)
             (*(int *)(*(int *)(iVar1 + 4 + DAT_006a5f78) + -4 + (param_1[5] + param_1[4]) * 4) *
              0x10 + DAT_006a5f30);
    puVar3 = (undefined4 *)FUN_00450050();
    *puVar3 = *puVar4;
    iVar1 = *(int *)(*(int *)(iVar1 + 4 + DAT_006a5f78) + -4 + (param_1[5] + param_1[4]) * 4);
    puVar4 = (undefined4 *)FUN_00450080();
    *puVar4 = *(undefined4 *)(iVar1 * 0x10 + 4 + DAT_006a5f30);
  }
  return;
}

