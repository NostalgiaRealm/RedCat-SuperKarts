import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {HelpNavigation} from '../source/help-navigation.js';
const data=JSON.parse(readFileSync(new URL('../public/assets/help/topics.json',import.meta.url)));

test('numeric contexts and retained aliases resolve every original topic',()=>{
  for(const topic of data.topics){
    const nav=new HelpNavigation(data,topic.contextId);
    assert.equal(nav.topic.id,topic.id);assert.equal(nav.resolve(topic.id),nav.topic);
  }
});
test('Back follows visited links rather than physical HLP topic order',()=>{
  const nav=new HelpNavigation(data,5);
  assert.equal(nav.canBack,false);assert.equal(nav.back(),false);
  nav.visit(7,{scrollTop:712,focus:1});nav.visit(13,{scrollTop:320,focus:0});
  assert.equal(nav.topic.title,'Spelregels');
  assert.equal(nav.back(),true);assert.equal(nav.topic.contextId,7);
  assert.deepEqual(nav.current,{id:data.contextMap[7],scrollTop:320,focus:0});
  nav.back();assert.equal(nav.topic.contextId,5);assert.equal(nav.current.scrollTop,712);
  assert.equal(nav.canBack,false);
});
test('Contents uses SYSTEM contents and history can revisit a branch',()=>{
  const nav=new HelpNavigation(data,10);nav.visit(8);nav.contents();
  assert.equal(nav.topic.id,data.startTopic);
  assert.deepEqual(nav.history,[data.startTopic,data.contextMap[8],data.contextMap[10]]);
  nav.back();nav.visit(13);nav.back();assert.equal(nav.topic.contextId,8);
});
test('unresolved targets leave navigation state untouched',()=>{
  const nav=new HelpNavigation(data,2),before=JSON.stringify(nav.stack);
  assert.equal(nav.visit('javascript:alert(1)'),false);assert.equal(nav.visit(999),false);
  assert.equal(JSON.stringify(nav.stack),before);assert.equal(nav.history.length,1);
});
test('raw keyword index and link contexts agree with all authored topic destinations',()=>{
  const nav=new HelpNavigation(data);
  assert.equal(data.schema,2);assert.equal(data.keywordIndex.length,13);
  for(const keyword of data.keywordIndex)
    for(const context of keyword.contextIds)assert.ok(nav.resolve(context).keywords.includes(keyword.keyword));
  assert.equal(nav.resolve(1).keywords[0],'Hoofdmenu');
  assert.equal(nav.resolve(4).keywords[0],'Highscores');
  const links=data.topics.flatMap(t=>t.links);assert.equal(links.length,9);
  for(const link of links){assert.equal(nav.resolve(link.contextId).id,link.target);assert.equal(link.kind,'jump');}
  assert.equal(links.filter(link=>link.preserveFont).length,8);
  assert.ok(data.topics.every(t=>t.browsePrevious===null&&t.browseNext===null));
});
