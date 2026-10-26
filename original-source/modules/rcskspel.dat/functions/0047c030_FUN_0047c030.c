/*
 * FUN_0047c030 at 0047c030
 * undefined FUN_0047c030(void)
 * Address ranges: 0047c030-0047c1a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047c030(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 unaff_EBP;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  int *unaff_retaddr;
  int iStack_c;
  
  iVar3 = FUN_0047d670();
  uVar1 = *(uint *)(iVar3 + 8);
  iStack_c = 0;
  puVar8 = &DAT_00544f08;
  do {
    pbVar10 = &DAT_004d2404;
    if (*(byte **)(iVar3 + 4) != (byte *)0x0) {
      pbVar10 = *(byte **)(iVar3 + 4);
    }
    uVar2 = *puVar8;
    uVar7 = uVar2;
    if (uVar1 <= uVar2) {
      uVar7 = uVar1;
    }
    bVar11 = false;
    iVar4 = 0;
    bVar12 = true;
    pbVar9 = (byte *)puVar8[-1];
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      bVar11 = *pbVar9 < *pbVar10;
      bVar12 = *pbVar9 == *pbVar10;
      pbVar9 = pbVar9 + 1;
      pbVar10 = pbVar10 + 1;
    } while (bVar12);
    if (!bVar12) {
      iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
    }
    if (((iVar4 == 0) && (uVar1 <= uVar2)) && (uVar2 == uVar1)) {
      if (iStack_c != -1) {
        if (iStack_c == DAT_00544ef8) {
          return;
        }
        iVar4 = FUN_0047f750();
        iVar3 = *(int *)(iVar4 + 0x74);
        if (iVar3 != *(int *)(iVar4 + 0x78)) {
          uVar1 = (&DAT_00544f08)[DAT_00544ef8 * 4];
          do {
            pbVar10 = &DAT_004d2404;
            if ((byte *)(&DAT_00544f04)[DAT_00544ef8 * 4] != (byte *)0x0) {
              pbVar10 = (byte *)(&DAT_00544f04)[DAT_00544ef8 * 4];
            }
            uVar2 = *(uint *)(iVar3 + 8);
            uVar7 = uVar2;
            if (uVar1 <= uVar2) {
              uVar7 = uVar1;
            }
            bVar11 = false;
            iVar6 = 0;
            bVar12 = true;
            pbVar9 = *(byte **)(iVar3 + 4);
            do {
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              bVar11 = *pbVar9 < *pbVar10;
              bVar12 = *pbVar9 == *pbVar10;
              pbVar9 = pbVar9 + 1;
              pbVar10 = pbVar10 + 1;
            } while (bVar12);
            if (!bVar12) {
              iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            }
            if (((iVar6 == 0) && (uVar1 <= uVar2)) && (uVar2 == uVar1)) {
              (**(code **)(**(int **)(iVar3 + 0x10) + 0x14))(0);
              (**(code **)(*unaff_retaddr + 0x14))(1);
              DAT_00544ef8 = unaff_EBP;
              FUN_0048f010(unaff_EBP);
              return;
            }
            iVar3 = iVar3 + 0x14;
          } while (iVar3 != *(int *)(iVar4 + 0x78));
        }
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&param_1,&DAT_004d9d80);
      }
      goto LAB_0047c0b0;
    }
    puVar8 = puVar8 + 4;
    iStack_c = iStack_c + 1;
    if (0x544f57 < (int)puVar8) {
LAB_0047c0b0:
      iVar3 = FUN_0047d670();
      puVar5 = *(undefined1 **)(iVar3 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      FUN_004afce0(s__s__d____Couldn_t_find_music_set_004f86ac,
                   s_D__work_rcsk_Code_game_ReqSound__004f8688,0x99,puVar5);
      return;
    }
  } while( true );
}

