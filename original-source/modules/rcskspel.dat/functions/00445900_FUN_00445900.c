/*
 * FUN_00445900 at 00445900
 * undefined FUN_00445900(void)
 * Address ranges: 00445900-00445a05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445900(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  
  iVar1 = DAT_00543760;
  iVar7 = DAT_0053be40;
  iVar5 = DAT_0053ba18;
  bVar8 = DAT_004ef160 != DAT_0053be40;
  DAT_004ef160 = DAT_0053be40;
  if (bVar8) {
    if (DAT_00543764 != DAT_0053ba18) {
      if (0 < DAT_00543760) {
        puVar3 = &DAT_0053f998;
        iVar4 = DAT_00543760;
        do {
          *puVar3 = 0;
          puVar3 = puVar3 + 0xd0;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      DAT_00543764 = iVar5;
    }
    iVar4 = 0;
    if (0 < iVar1) {
      piVar6 = &DAT_0053f998;
      do {
        if ((((piVar6[-0xce] != 0) && (piVar6[-0xce] == iVar7)) &&
            ((piVar6[-0xcb] == iVar5 + 1 || (piVar6[-0xcb] == 0)))) && (*piVar6 == 0)) {
          iVar5 = piVar6[-0xcc];
          cVar2 = FUN_00446b80(iVar5);
          if (cVar2 == '\0') {
            if ((iVar5 < 0) || (0xd < iVar5)) {
              FUN_004afee0(s__s___d__Incorrect_path_type___d_004ef620,
                           s_D__work_rcsk_Code_game_pth_main__004ef5fc,0x300,iVar5);
            }
            if (*(code **)(&DAT_004ef04c + iVar5 * 0x14) == (code *)0x0) goto LAB_004459ed;
            cVar2 = (**(code **)(&DAT_004ef04c + iVar5 * 0x14))(iVar4);
          }
          else {
            cVar2 = FUN_00446c00(iVar4);
          }
          if (cVar2 != '\0') {
            *piVar6 = *piVar6 + 1;
          }
        }
LAB_004459ed:
        iVar4 = iVar4 + 1;
        piVar6 = piVar6 + 0xd0;
        iVar5 = DAT_0053ba18;
        iVar7 = DAT_0053be40;
      } while (iVar4 < DAT_00543760);
    }
  }
  return;
}

