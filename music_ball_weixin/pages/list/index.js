// pages/cart/index.js

Page({

  /**
   * 页面的初始数据
   */
  data: {

  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

   
  },
  play1: function(event) {
    var srcurl= 'https://downsc.chinaz.net/Files/DownLoad/sound1/201308/3381.mp3';
    const innerAudioContext = wx.createInnerAudioContext()
    innerAudioContext.autoplay = true
    innerAudioContext.src = srcurl
    },
    play2: function(event) {
      var srcurl= 'https://downsc.chinaz.net/Files/DownLoad/sound1/201702/8389.mp3';
      const innerAudioContext = wx.createInnerAudioContext()
      innerAudioContext.autoplay = true
      innerAudioContext.src = srcurl
      },
      play3: function(event) {
        var srcurl= 'https://downsc.chinaz.net/Files/DownLoad/sound1/201309/3558.mp3';
        const innerAudioContext = wx.createInnerAudioContext()
        innerAudioContext.autoplay = true
        innerAudioContext.src = srcurl
        },
        play4: function(event) {
          var srcurl= 'https://downsc.chinaz.net/Files/DownLoad/sound/huang/cd7/mp3/751.mp3';
          const innerAudioContext = wx.createInnerAudioContext()
          innerAudioContext.autoplay = true
          innerAudioContext.src = srcurl
          },
          play5: function(event) {
            var srcurl= 'https://downsc.chinaz.net/Files/DownLoad/sound/huang/cd7/mp3/745.mp3';
            const innerAudioContext = wx.createInnerAudioContext()
            innerAudioContext.autoplay = true
            innerAudioContext.src = srcurl
            },
            play6: function(event) {
              var srcurl= 'https://downsc.chinaz.net/Files/DownLoad/sound1/201307/3324.mp3';
              const innerAudioContext = wx.createInnerAudioContext()
              innerAudioContext.autoplay = true
              innerAudioContext.src = srcurl
              },
              play7: function(event) {
                var srcurl= 'https://downsc.chinaz.net/Files/DownLoad/sound1/202007/13183.mp3';
                const innerAudioContext = wx.createInnerAudioContext()
                innerAudioContext.autoplay = true
                innerAudioContext.src = srcurl
                },
  topage2:function(options){
    wx.navigateTo({
      url: '../index/index',
    })
    
  },
  

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})