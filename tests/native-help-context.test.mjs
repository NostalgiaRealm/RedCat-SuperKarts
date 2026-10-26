import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeHelpContext,nativeHelpNotice} from '../source/native-help-context.js';

const help=JSON.parse(fs.readFileSync(new URL('../public/assets/help/topics.json',import.meta.url)));
const topic=context=>help.topics.find(item=>item.id===help.contextMap[context]);

test('menu Help buttons resolve the original numeric contexts and topic titles',()=>{
  for(const [page,context,title]of [
    ['main',1,'Hoofdmenu'],['settings',2,'Instellingen'],
    ['controls',3,'Besturing'],['start-info',3,'Besturing'],
    ['adventure',5,'Spelerlijst (Avontuur )'],['briefing',7,'Overzicht (Avontuur)'],
    ['countries',10,'Racekeuze'],
  ]){
    assert.equal(nativeHelpContext(page),context,page);
    assert.equal(topic(context)?.title,title,page);
  }
});

test('character and debrief Help distinguish Adventure from Quickrace',()=>{
  for(const [page,playMode,context,title]of [
    ['characters','quickrace',9,'Spelerkeuze (Quickrace)'],
    ['characters','adventure',6,'Spelerkeuze (Avontuur)'],
    ['debrief','quickrace',12,'Einde race (Quickrace)'],
    ['debrief','adventure',11,'Einde race (Avontuur)'],
  ]){
    assert.equal(nativeHelpContext(page,{playMode}),context,`${page}/${playMode}`);
    assert.equal(topic(context)?.title,title);
  }
  assert.equal(nativeHelpContext('characters'),9);
  assert.equal(nativeHelpContext('debrief'),12);
});

test('country information uses notice 46; unsupported screens do not invent a Help target',()=>{
  assert.equal(nativeHelpNotice('country-info'),46);
  for(const page of ['country-info','viewer','help','prompt','intro','score-name','profile-name','unknown','toString'])
    assert.equal(nativeHelpContext(page),null,page);
  for(const page of ['main','characters','debrief','settings','unknown'])
    assert.equal(nativeHelpNotice(page),null,page);
});

test('existing Highscores direct-topic access retains the original HLP context 4',()=>{
  assert.equal(nativeHelpContext('highscores'),4);
  assert.equal(topic(4)?.title,'Highscores');
});
