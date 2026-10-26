/*
 * FUN_00440c30 at 00440c30
 * undefined FUN_00440c30(void)
 * Address ranges: 00440c30-00440d68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440c30(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  DAT_0053ba14 = FUN_0042a4d0();
  FUN_004315a0(s_Ronde__d__Pos__d__Rondetijd__3_2_004ecbf8,DAT_0053ba18 + 1,DAT_0053be60 + 1,
               (double)((float)DAT_0053ba14 * 0.001));
  if ((DAT_0053ba18 < 0) || (0x3e6 < DAT_0053ba18)) {
    FUN_004afee0(s__s___d__Illegal_index_for_nr_of_l_004ecc40,
                 s_D__work_rcsk_Code_game_Tr_finis__004ecc1c,0x2a,DAT_0053ba18);
  }
  iVar1 = DAT_0053be5c;
  iVar2 = DAT_0053ba14;
  *(int *)(&DAT_0053c23c + DAT_0053ba18 * 4) = DAT_0053ba14;
  if (((iVar2 < iVar1) && (0 < iVar2)) || (iVar1 == 0)) {
    DAT_0053be5c = iVar2;
  }
  DAT_0053ba18 = DAT_0053ba18 + 1;
  if (DAT_0053ba1c < DAT_0053ba18) {
    DAT_0053ba18 = DAT_0053ba1c;
  }
  if (DAT_0053ba18 < 0) {
    DAT_0053ba18 = 0;
  }
  if (DAT_0053ba18 == DAT_0053ba1c + -1) {
    FUN_00430610();
    iVar2 = DAT_0053ba14;
  }
  iVar1 = DAT_0053d32c;
  if (iVar2 < DAT_0053ba0c) {
    FUN_00430610();
    DAT_0053ba0c = DAT_0053ba14;
    if ((DAT_0053d32c < 0) || (9 < DAT_0053d32c)) {
      FUN_004afee0(s__s___d__Incorrect_nr_of_time_che_004ecc9c,
                   s_D__work_rcsk_Code_game_Tr_finis__004ecc78,0x55,DAT_0053d32c);
    }
    iVar1 = DAT_0053d32c;
    if (0 < DAT_0053d32c) {
      puVar3 = &DAT_0053d2d8;
      puVar4 = &DAT_0053d300;
      for (iVar2 = DAT_0053d32c; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
  }
  DAT_0053d32c = 0;
  DAT_004ed1c0 = iVar1;
  FUN_0042a210();
  return;
}

